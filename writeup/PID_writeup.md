"
# **PID CONTROL Project**
### Adalberto Gonzalez

The goals / steps of this project are the following:

* In this project I'll revisit the lake race track from the Behavioral Cloning Project. This time, however, I'll implement a PID controller in C++ to maneuver the vehicle around the track!


## [Rubric](https://review.udacity.com/#!/rubrics/824/view) Points
###Here I will consider the rubric points individually and describe how I addressed each point in my implementation.  

---
###Writeup / README


###Compilation

####1. Your code should compile.

The code for this exercise compile with cmake .. & Make .  
<img src=./output_images/compile.jpg alt="image1" height=200 />

###Implementation


####2. The PID procedure follows what was taught in the lessons..

The base algorithm follow what's presented in the lessons


###Reflection

####3. Describe the effect each of the P, I, D components had in your implementation.

**P**roportional: The P controller controls the speed smoothly, allowing it to slow down as it approaches it's target.
**I**ntegral: The I is the running sum of previous errors. So when your error is very small, the integral comes into action,so that it travels fast enough to shrink the error, but not too fast,because then it might run the risk of overshooting.
**D**erivative:  The D component job is to predict the future value for the error, and then make the speed act accordingly. If D thinks it will overshoot, it will slow it down.


I tune my constants is as follows based on :
("An introduction and tutorial for PID controllers, by George Gillard"9)

- Set Kp, Ki, and Kd to 0. This will disable them for now.
- Increase Kp until the error is fairly small, but it still gets from the beginning to nearly the end quickly enough.
- Increase Kd until any overshoot you may have is fairly minimal. But be careful with Kd – too much will make it overshoot.
- Increase Ki until any error that is still existing is eliminated. Start with a really small number for Ki, don't be surprised if it is as small as 0.0001 or even smaller.
- Using the rules of tuning the constants (in the table on the previous page), you can change around the constants a little bit to get it working to the best performance.

To find my hyperparameters I applied on a  simple binary search logic to close the gap on the values i could choose ( i left some of them in the code for reference)
this tunnng leadme to a more stable steering.

<img src=./output_images/result.gif alt="image1" height=400 />

  
This code has a lot of room to improve we can work the bumpiness of the steering by by porsuing a more robusr hyperparameter setting like twiddle.

As you could see this projet is far from being completed because even when i feel i completed the task, there is a enormous oportunity to growth and improvement, i hope i can come back to this project to improve on my thoughts on new learnings!

