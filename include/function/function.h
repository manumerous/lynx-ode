
namespace numerical_integration {

class Function {
 public:
  Function();

  virtual double evaluate(double x) = 0;
};

}  // namespace numerical_integration
