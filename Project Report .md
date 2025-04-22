# Project Report of

# Programming Language I Lab

# (CSE115.11)

## Submitted to

Rejuana Islam  
Lab Instructor

# North South University

### Department of Electrical and Computer Engineering

## Submitted by

Mir Inan Islam  
ID: 2513127642

Submission Date: 21.04.2025

# 

# 

# ByteWave

1. ## Introduction:

   **“ByteWave”, an Internet Service Provider (ISP) Management System** is a C-based console application designed to simulate core functionalities of a website based Internet Service Provider’s user and administrator interfaces. It allows a user to sign up, log in, select plans that they wish to use and have an user interface to manage data plans and check for billing information, while the administrator can manage user data, update plan details such as changing prices, internet speed, and send billing notifications to users. This system demonstrates file handling, structure usage, nested functions for console interface design according to real life counterparts and a logical flow control in C programming language.

2. ## Objectives:

* To build a functioning management system for an ISP.   
* To apply knowledge of C programming, including structures, arrays, strings, file handling, function planning and brainstorming.  
* To differentiate functionalities between admin and user roles.  
* To demonstrate a real-life simulation of ISP operations such as plan selection and billing to users.

  ## 3\. Features and Functionalities:

####         **Login / Signup System**

* A login page shared by admin and users with hardcoded credentials for admins to access administrative functionalities and users to login.  
* Admin credentials are hardcoded for secure access.

#### **User Functionality**

* View your own active plan.  
* Receive due billing notifications.

#### **Admin Functionality**

* Log in with specific ID: `2513127642` and password: `CSE115`.  
* View and manage all registered users.  
* Add new users manually.  
* Delete users by entering their ID.  
* Add, update, or remove plan prices.

#### **Plan & Billing Management**

* Monthly Plans: initialised the “plan.txt” file along with the plans defined as below  
  * Iron – Tk. 525  
  * Bronze – Tk. 680  
  * Silver – Tk. 890  
  * Gold – Tk. 1050  
  * Platinum – Tk. 1260  
  * Diamond – Tk. 1575  
  * Sapphire – Tk. 2100

  ## 4\. Limitations

* ## No real banking or mobile recharge integration \- paying due bill manually. 

* ## The platform works in CLI only — no graphical interface

* Provide feedback and rate the system (Design & Code ratings stored in a file).

  ## 5\. Topics Covered:

* Structures (struct) for User and Billboard .  
* Loops, conditionals, and arrays.  
* Function pointers and switch-case logic.  
* Basic input/output operations.  
* Menu-driven interface design.  
* Structured Data Handling.

## 6\. Difficulties Faced

 File handling has been one of the most important parts of this project and also one of the hardest to implement with most of my work yet to be completed. Balancing the functionalities over all for a clean look at the code and learning new concepts were tricky at times. Although it has been fun to learn and implement it right away and to watch it tie all together and work.

## 7\. Future Work

* Better integration of the payment system within the console for ease of payment.  
* Adding a ticket system for users to file tickets to problems for the team to resolve it.  
* Password masking for security purposes.  
* Time integration for the billing system.  
* Enhancement of User Interface  
* Use ASCII art / colored terminal output (using ANSI escape codes) for better user experience.

* Later: Build a GUI using C libraries like GTK or integrate with a frontend via Python/C++ backend.