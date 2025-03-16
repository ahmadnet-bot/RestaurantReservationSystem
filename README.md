# 🍔 Tasty Burgers - Reservation and Order System

##  Project Overview
The **Tasty Burgers Reservation System** is a simple C-based console application that allows users to place, cancel, and manage burger orders. It provides functionalities such as ordering different types of burgers, canceling an order, and checking the total revenue (admin feature).

---

##  Features
- ** Order Burgers:** Customers can order different types of burgers:
  - ** Chicken Burger** - **$15**
  - ** Ham Burger** - **$17**
  - ** Vegie Burger** - **$13**
  - Orders of **5 or more burgers** receive a **10% discount**.
- ** Cancel an Order:** Users can enter their receipt number to cancel an order.
- ** Admin Revenue Calculation (Hidden Feature):** 
  - Entering the hidden option `9` and providing the correct password (**TastyBurger**) will display the **total revenue** for the day.

---

##  How to Use
### **Compile the Program**
Use a C compiler like `gcc` to compile the file:
```bash
gcc -o ResBooking ResBooking.c
