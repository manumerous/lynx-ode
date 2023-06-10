
namespace numerical_integration {

class AbstractFunction {
 public:
  Function();

  virtual double evaluate(double x) = 0;
};

}  // namespace numerical_integration
