#include <iostream>
#include <conio.h>

#include "../boolean-functions/binary.h"
#include "../boolean-functions/boolean_function.h"

using namespace discr_math;
using std::cout;
using std::endl;

static const int NumOfArgs = 4;

int main( int argc, char **argv ) {
  //freopen("8.txt", "w", stdout);

  binary Signature = (binary(16) + binary(192)).pow(1 << (NumOfArgs - 3));
  Signature.resize(1 << NumOfArgs);

  auto Sign = boolean_function::signature(Signature);
  boolean_function Func(Sign);
  boolean_function::truth_table Table(Sign);

  cout << Func << endl << endl
       << Table << endl << endl
       << boolean_function::ccnf((boolean_function::signature)Func) << endl << endl
       << boolean_function::cdnf((boolean_function::signature)Func) << endl << endl
       << boolean_function::rdnf((boolean_function::signature)Func) << endl << endl
       << boolean_function::karnaugh_map((boolean_function::signature)Func) << endl << endl
       << boolean_function::zhegalkin_poly((boolean_function::signature)Func) << endl << endl;

  if (Func.isZeroSaving())
    cout << "Saves zero" << endl;
  if (Func.isOneSaving())
    cout << "Saves one" << endl;
  if (Func.isSelfDual())
    cout << "Self-Dual" << endl;
  if (Func.isMonotonous())
    cout << "Monotonous" << endl;
  if (Func.isSymmetric())
    cout << "Symmetric" << endl;

  _getch();

  return 0;
}
