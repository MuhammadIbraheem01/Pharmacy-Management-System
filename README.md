# Pharmacy-Management-System
📌 Introduction
The Pharmacy Management System is a console-based C++ application designed to help manage a pharmacy’s inventory, sales, and customer interactions in an efficient and organized manner. Managing medicines, their pricing, stock availability, and customer choices can become challenging, especially in a manual setting. This program aims to digitize and simplify those day-to-day pharmacy operations.

The project is written in standard C++ and uses arrays, simple file handling, and functions to store, retrieve, and process data related to medicines. It supports both an admin/owner mode and a customer mode, providing different features for each user role.

🩺 Problem Statement
In the real world, many small to mid-sized pharmacies still rely on paper-based systems or purely manual processes to manage their medicine inventories. This approach is prone to errors, time-consuming, and difficult to scale. Problems such as:

Stock mismanagement

Pricing errors

Difficulty tracking profit margins

Limited customer engagement

can all reduce the efficiency of pharmacy operations. There is a need for a simple, affordable, and reliable digital solution that does not require heavy hardware or cloud subscriptions but still keeps records safe and easy to manage.

🎯 Project Objectives
This project aims to:

✅ Provide an easy-to-use digital system to manage medicines
✅ Reduce manual errors in stock and pricing
✅ Improve accessibility for customers to view available products
✅ Support owners in keeping track of medicine details and profitability
✅ Provide a solid base to expand with more advanced features in the future

🌟 Features
The Pharmacy Management System provides the following key features:

Add Medicines

Admin can add new medicines with their name, wholesale price, selling price, and stock.

Medicine details are saved to a text file for persistence.

Update Medicines

Admin can update stock or selling prices of existing medicines.

All updates are reflected immediately in both memory and file storage.

Display Medicines

Medicines are displayed with names, prices, and available stock.

Sorted views help in easy price-based comparisons.

Recommended Medicines & Categories

Hardcoded recommended medicines are available for customers to browse.

Predefined categories (e.g., Painkillers, Antibiotics) help customers explore options.

Secure Owner Login

A simple hard-coded owner login provides role-based access.

Admin-only features are protected from customer access.

File-Based Storage

All medicine data is saved to a text file to preserve data between runs.

No separate database required, keeping it easy to manage.

Color-coded Output

For better readability, colored console outputs distinguish messages, errors, and menus.

🗂️ System Architecture Overview
The project is structured with a modular C++ design, making use of:

Global Arrays

Store medicine names, prices, stocks, and wholesale prices in memory for fast access.

File Handling

Text files (e.g., medicines.txt) store all medicine data persistently.

Functions

Each feature, such as adding medicines or updating stock, is handled by a separate function for clarity.

Main Menu Loops

Owner menu and customer menu loops present options repeatedly until the user logs out.

Hard-coded Credentials

Simplifies testing and prevents unauthorized use during demonstrations.

Sorting

Uses bubble sort for arranging medicines by selling price in descending order, allowing customers and owners to spot high-value products easily.

📊 Detailed Feature Explanation
➤ Add Product

The owner can input medicine details, which are saved to arrays and written to a file immediately.

Prevents duplicate or empty entries.

➤ Update Price / Stock

Owner can search by medicine name to modify its price or stock quantity.

Edits are saved both in memory and to file.

➤ Display Medicines

Owner and customer can list all medicines with their details.

The owner sees the full list with wholesale and selling price; customers see a simpler list.

➤ Recommended Medicines & Categories

Customer mode includes a hardcoded set of recommended medicines (for marketing purposes).

Categories like Antibiotics, Painkillers, and Cold Medicines help customers navigate easily.

➤ Login

Owner login is protected by username and password prompts, with hard-coded values for testing.

Customers do not require a password but can view and explore the medicines.

➤ File Management

Medicine records are appended to a text file when added or updated.

When the program starts, it loads existing records from the file to rebuild the in-memory arrays.

🖥️ Code Flow
Program starts

Loads medicines from file into arrays

Shows user choice: Owner or Customer

Owner Mode

Login required

Presents options: Add, Update, View Medicines, etc.

Updates saved to file

Customer Mode

No login needed

Can view medicines, see recommended products, and explore categories

Loop

Keeps running until user exits

🛠️ How to Run
Clone or download the project folder

Open the .cpp file in your preferred IDE (Code::Blocks, Dev-C++, Visual Studio, etc.)

Make sure medicines.txt exists in the same folder

Build and run the program

⚠️ Important:
This project is designed for a simple console environment and does not use advanced GUI frameworks or a database engine.

🚀 Future Improvements
✅ Add proper user signup & role management
✅ Add bill calculations and payment tracking
✅ Use a relational database instead of text files
✅ Build a graphical user interface
✅ Add expiry date & batch number tracking for medicines

🙌 Credits
This project was developed by [Your Name / Your Team Name] as a practice project in C++.
It showcases skills in file handling, arrays, sorting, and functional programming with C++ for beginner to intermediate learners.
