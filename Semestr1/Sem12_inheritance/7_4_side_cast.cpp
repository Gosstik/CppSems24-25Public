// side cast is prohibited

struct Granny {};
struct Mom: Granny {};
struct Dad: Granny {};

struct Son1: Mom, Dad {};
struct Son2: Dad, Mom {};

int main() {
  Son1 s1;
  Mom& m1 = s1;
  Dad& d1 = static_cast<Dad&>(m1); // CE
}
