# This is a corrected tiling algortihm for imperfectly nested loops
# It is based on the tiling v.3 algorithm
# Changes:
# Petit is replaced by Clan. Stop problems with parsing. Still possibility to use Petit.
# Base of statements and dependences from Clan and Candl.
# R*, R+ only beetwen statements.
# Extending before codegen according to scattering.
# Object programming.
# LT and GT as hyperplanes.
# Cleaning!!!

import glob, os
import clanpy
from termcolor import colored

try:
    import islpy as isl
except ImportError, e:
    print e
    print "pip install ispy"
    sys.exit()

DEBUG = True


def tile(plik, block, permute, output_file="", L="0", SIMPLIFY="False", perfect_mode = False, parallel_option = False, rplus_file = ''):
    it = InitTile(plik, block)


class InitTile:

    input_file = ""
    block = []
    permute = "False"
    output_file = ""
    SIMPLIFY = False
    parallel = False

    cl = False  # clan & candl data

    # Let's start
    def __init__(self, input_file, block, permute=False, output_file="", SIMPLIFY=False, parallel_option = False):

        self.input_file = input_file

        # FILE OUT
        filePaths = glob.glob(input_file)
        if(output_file != ""):
            self.output_file = output_file
        else:
            for filePath in filePaths:
                base = os.path.basename(filePath)
                output_file = os.path.splitext(base)[0] + ".traco" + os.path.splitext(base)[1]

        self.output_file = output_file
        # =============

        if(DEBUG):

            print ''
            print colored('/\__  _\ /\  == \   /\  __ \   /\  ___\   /\  __ \   ', 'green')
            print colored('\/_/\ \/ \ \  __<   \ \  __ \  \ \ \____  \ \ \/\ \  ', 'green')
            print colored('   \ \_\  \ \_\ \_\  \ \_\ \_\  \ \_____\  \ \_____\ ', 'green')
            print colored('    \/_/   \/_/ /_/   \/_/\/_/   \/_____/   \/_____/ ', 'green')
            print ''
            print '       An Automatic Parallelizer and Optimizer'
            print ' based on the TRansitive ClOsure of dependence graph'
            print '              traco.sourceforge.net               '
            print ''

            print '=== TRACO START ==='
            print 'Input file   ' + self.input_file
            print 'Output file  ' + self.output_file


        # structure & dependence analysis
        self.ClanAndCandl()

        if(DEBUG):
            print 'Statements:  ' + str(len(self.cl.statements))
            for st in self.cl.statements:
                print '  -> ' + st.body
                print '     ' + ','.join(st.scatering)

            print 'Dependences: ' + str(len(self.cl.deps))

            for d in self.cl.deps:
                print 'S' + str(d.source) + ' -> ' + 'S' + str(d.destination)
                print 'delta: ' + str(d.delta)
                print d.relation

            self.block = block.split(',')
            for i in range(len(self.block),self.cl.maxdim):
                self.block.append(self.block[len(self.block)-1])

            print 'Tile block: ' + ','.join(self.block)


            print 'OK. The loop to transform is ready.'
            print '===  TRACO GO  ==='

            bstile = BaseTile(self.cl)

            bstile.CreateTILE(self.block)




    def ClanAndCandl(self):

        self.cl = clanpy.ClanPy()
        self.cl.loop_path = self.input_file
        self.cl.Load()
        self.cl.DepAnalysis()


class Tile_Statement:
    tile_iterators = []
    iterators = []  # copy orygina_iterators
    TILE = None
    cl_statement = None # Reference

    def __init__(self, st):
        self.cl_statement = st

        self.iterators = self.cl_statement.original_iterators

        for iterator in self.cl_statement.original_iterators:
            self.tile_iterators.append(iterator.encode('ascii', 'ignore') * 2)


class BaseTile:
    tile_statements = []
    cl = None

    def __init__(self, cl):
        self.cl = cl

        for st in cl.statements:
            tile_st = Tile_Statement(st)
            self.tile_statements.append(tile_st)


    def CreateTILE(self, BLOCK):
        i = 0

        is_i = isl.Set(self.cl.statements[i].domain_map)
        print is_i

        tile = is_i

        j =0
        for symvar in self.tile_statements[i].tile_iterators:
            tile = tile.add_dims(isl.dim_type.param, 1)
            tile = tile.set_dim_name(isl.dim_type.param, tile.dim(isl.dim_type.param)-1, symvar)

            c = isl.Constraint.ineq_from_names(tile.get_space(), {symvar: 1, 1:0})
            tile = tile.add_constraint(c)

            bl = int(BLOCK[j])                                                                          #  j <= 15 + 16jj
            c = isl.Constraint.ineq_from_names(tile.get_space(), {self.tile_statements[i].iterators[j]: -1, symvar:bl,  1:bl-1})
            tile = tile.add_constraint(c)

            c = isl.Constraint.ineq_from_names(tile.get_space(), {self.tile_statements[i].iterators[j]: 1, symvar:-bl})
            tile = tile.add_constraint(c)

            j = j+1







        print tile



# klasa do tilingu
# zrob tile
# zrob lt gt
# sprawdz czy sa same +
# wywal zaleznosci jesli blok = 1 na gniezdzie
#policz R+ i inne
# zrob bis, generuj kod

#wykryj rownoleglosc
