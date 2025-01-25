# Grocery-Store-Mangement-System
A simple Grocery Store Management System written in C++ | Semester Project | OOP (Object Oriented Programming)

## **Overview**
This project implements an **Object-Oriented Programming (OOP)** approach to create a comprehensive management system for a grocery store chain. It automates processes and improves the shopping experience for customers both in-person and online. The system supports multiple user roles (Admin, Manager, Customer) and includes modules for registration, login, inventory management, online shopping, payment, and checkout simulation. Binary file handling was used to save data.

---

## **Project Features**

### **1. Registration**
- **Customer Registration**:
  - Validate 13-digit CNIC and 9-character password with at least one uppercase letter and one numeric digit.
  - Prevent duplicate registrations and handle typing mistakes in password confirmation.
  - Store additional details like gender, phone number, and address.
- **Manager Registration**:
  - Managers can only be registered by Admins.
  - Admins assign managers to specific store locations.

### **2. Login**
- Supports login for Admin, Manager, and Customer with appropriate error handling for incorrect credentials.

### **3. Home Screen & Submenus**
- Different home screens and menus are displayed based on the user role after login.

### **4. Manage Stores and Users** (Admin Only)
- Admins manage:
  - Records of all stores across the country.
  - Manager registrations.
  - Removal of spam customer accounts.

### **5. Product Catalog** (Admin Only)
- Manage a centralized catalog of all possible product categories.
- Categories include:
  - **Food**: Perishable (Meat, Dairy, Fruits, Vegetables) and Non-Perishable (Snacks, Spices, Grains, Cereal).
  - **Personal Hygiene**: Shampoo, Soap, Hand Sanitizer.
  - **Household Cleaning**: Detergent, Dish Soap, Washroom Cleaner.
- Admins can add, remove, and update products, ensuring data is saved in a separate catalog file.

### **6. Inventory Management** (Manager Only)
- Each store has its own inventory managed by its respective manager.
- Managers can:
  - Add, update, and remove inventory items for their store.
  - View and search inventories of other stores.
- Real-time updates are reflected in store-specific inventory files.

### **7. Online Shopping** (Customer Only)
- Customers can:
  - Browse the product catalog and add items to their cart.
  - Finalize cart at checkout with multiple payment options (Cash on Delivery, Debit/Credit Card, Easypaisa, JazzCash, etc.).
  - Provide feedback and ratings for stores.
- Inventory is updated based on order quantity.

### **8. Payment**
- Payment methods include:
  - Cash on Delivery (additional charges apply based on customer location).
  - Debit/Credit Card.
  - Easypaisa, JazzCash, and other gateways.
 
## How to Run
1. Clone the repository:
   ```bash
   git clone https://github.com/Zain-Rizwan/Word2Vec-Spam-Detection.git

2. Run Grocery_store.h as main file using c++ compiler.
