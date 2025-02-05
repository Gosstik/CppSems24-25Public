#include <exception>
#include <iostream>

void TerminateHandler() {
  std::cout << "First custom terminate function" << std::endl;

  std::exception_ptr eptr = std::current_exception();
  if (eptr) {
    std::cout << "Terminate is called because of exception" << std::endl;
    std::rethrow_exception(eptr);  // throw exception inside terminate ???
  }
  std::cout << "Call to abort()" << std::endl;
  std::abort();
}

int main() {
  std::set_terminate(TerminateHandler);

  std::terminate();
  // throw 1;
}
