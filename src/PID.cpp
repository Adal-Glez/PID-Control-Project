#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
    this -> Kp = Kp;
    this -> Kd = Kd;
    this -> Ki = Ki;
    
    this->p_error = 0.0;
    this->i_error = 0.0;
    this->d_error = 0.0;
    
   
    
    
}

void PID::UpdateError(double cte) {
    
    d_error = cte - p_error; // assume timestep is 1
    p_error = cte;
    i_error += cte; //// I controller will accumulate the error
    
}

double PID::TotalError() {
    
    double total_error = -Kp * p_error - Ki * i_error - Kd * d_error;
    //double total_error = Kp * p_error + Ki * i_error + Kd * d_error;
    
    if (total_error > 1) total_error = 1;
    if (total_error < -1) total_error = -1;
    return total_error;
}


/*
//twiddle algorithm for a PID controller python
# Make this tolerance bigger if you are timing out!
def twiddle(tol=0.2):
 p = [0, 0, 0]
 dp = [1, 1, 1]
 robot = make_robot()
 x_trajectory, y_trajectory, best_err = run(robot, p)
 while ( sum(dp) > tol):
  for i in range(len(p)):
   p[i]+=dp[i]
   robot = make_robot()
   x_trajectory, y_trajectory, err = run(robot , p)

   if err < best_err:
    best_err = err
    dp[i] *=1.1
   else:
    p[i] -= 2*dp[i]
    robot = make_robot()
    x_trajectory, y_trajectory, err = run(robot , p)

    if err < best_err:
     best_err = err
     dp[i] *=1.1
    else:
     p[i] += dp[i]
     dp[i] *= 0.9
 return p, best_err
*/
