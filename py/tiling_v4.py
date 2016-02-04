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
            print '/\__  _\ /\  == \   /\  __ \   /\  ___\   /\  __ \   '
            print '\/_/\ \/ \ \  __<   \ \  __ \  \ \ \____  \ \ \/\ \  '
            print '   \ \_\  \ \_\ \_\  \ \_\ \_\  \ \_____\  \ \_____\ '
            print '    \/_/   \/_/ /_/   \/_/\/_/   \/_____/   \/_____/ '
            print ''
            print '       An Automatic Parallelizer and Optimizer'
            print ' based on the TRansitive ClOsure of dependence graph'
            print '              traco.sourceforge.net               '
            print ''

            print '=== TRACO START ==='
            print 'Input file   ' + self.input_file
            print 'Output file  ' + self.output_file

