#if !defined(Already_Included_elim)
#define Already_Included_elim

#include <stdio.h>
#include <basic/Tuple.h>
#include <omega/Relations.h>
#include <string>

namespace omega {

class elimination_info {
public: 
  elimination_info();
  elimination_info(const Tuple<Relation> &sets);
  bool may_eliminate(Variable_ID v);
  bool any_eliminated()               { return eliminated.size()   >  0; }
  bool is_eliminated(Variable_ID v)   { return eliminated.index(v) != 0; }
  void eliminate(Variable_ID v)       { eliminated.append(v); }
  Relation project_eliminated(NOT_CONST Relation&R);
  Relation project_eliminated(const Relation &r, const Relation &known);
  void print_eliminated(FILE *out);
  std::string print_eliminated_to_string();
private:
  Tuple<Variable_ID> eliminated;
  int never_eliminate_lt;
};

int max_fs_arity(const Constraint_Handle &c);

} // namespace

#endif
