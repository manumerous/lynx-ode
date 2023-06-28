#include "common/Types.h"

namespace lynx_ode {

class Trajectory {
 public:
  Trajectory();
  Trajectory(size_t InitialNumTrajectoryElements) { reserveSpace(InitialNumTrajectoryElements); }

  void appendValue(scalar_t time, const vector_t& values) {
    timeStampArray.emplace_back(time);
    stateArray.emplace_back(values);
  }

  void reserveSpace(size_t numTrajectoryElements) {
    stateArray.reserve(numTrajectoryElements);
    timeStampArray.reserve(numTrajectoryElements);
  }

  scalar_array_t getTimeStamps() { return timeStampArray; }
  vector_array_t getValues() { return stateArray; }
  scalar_array_t getSingleStateValues(size_t stateIndex) {
    scalar_array_t output;
    output.reserve(stateArray.size());
    for (int i = 0; i < stateArray.size(); i++) {
      output.emplace_back(stateArray[i][stateIndex]);
    }
    return output;
  }

 private:
  scalar_array_t timeStampArray;
  vector_array_t stateArray;
};

}  // namespace lynx_ode