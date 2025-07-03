#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<fstream>
#include<string>
#include<windows.h>
using namespace std;
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"
// Prototypes
void mainHeader();
string ownerMenu();
char customerMenu();
string who();
void addProduct();
void updatePrice();
void updateStock();
void clearScren();
void sortedMedicine();
void viewPrice();
void displayMedicine();
void displayProduct();
void hardcodedCategories();
void recommendedMedicines();
void delivery();
void Discounts();
void SeeDiscount();

// Medicine Array Names
const int TOTAL_MEDICINE = 25;
int medicine_count = 0;
string nameA[TOTAL_MEDICINE];
string priceA[TOTAL_MEDICINE];
string stockA[TOTAL_MEDICINE];
string wholeSaleA[TOTAL_MEDICINE];
int main()
{
    while (true)
    {
        system("cls");
        string w = who();
        if (w == "ADMIN")
        {
            string adminOption;
            while (true)
            {
                system("cls");
                adminOption = ownerMenu();
                if (adminOption == "1")
                {
                    addProduct();
                }
                else if (adminOption == "2")
                {
                    updatePrice();
                }
                else if (adminOption == "3")
                {
                    updateStock();
                }
                else if (adminOption == "4")
                {
                    sortedMedicine();
                    displayProduct();
                }
                else if (adminOption == "5")
                {
                    displayMedicine();
                }
                else if (adminOption == "6")
                {
                	Discounts();
				}
                else if (adminOption == "7")
                {
                    cout << "Logging out..." << endl;
                    break;
                }
                else
                {
                    cout << "Invalid option." << endl;
                }
                clearScren();
            }
        }
        else if (w == "CUSTOMER")
        {
            char customerOption;
            while (true)
            {
                customerOption = customerMenu();
                if (customerOption == '1')
                {
                    displayMedicine();
                }
                else if (customerOption == '2')
                {
                    viewPrice();
                }
                else if (customerOption == '3')
                {
                    hardcodedCategories();
                }
                else if (customerOption == '4')
                {
                    recommendedMedicines();
                }
                else if (customerOption == '5')
                {
                    delivery();
                }
                else if (customerOption =='6')
                {
                	SeeDiscount();
				}
                else if (customerOption == '7')
                {
                    cout << "Logging out..." << endl;
                    break;
                }
                else
                {
                    cout << "Invalid option." << endl;
                }
                clearScren();
            }
        }
        else
        {
            cout << "Invalid login." << endl;
        }
        clearScren();
    }
}

void clearScren()
{
    cout << "Press any button to continue..." << endl;
    getch();
    system("cls");
}

void mainHeader()
{
    cout <<CYAN<< "*******************************************************" << endl;
    cout <<BOLD<<CYAN<< "**             PHARMACY MANAGEMENT SYSTEM            **" << endl;
    cout <<CYAN<< "*******************************************************" << endl
         << endl;
}

string ownerMenu()
{
    mainHeader();
    cout << GREEN<< "ADMIN MENU >" << endl;
    cout << BLUE<< "1- Add Product" << endl;
    cout << BLUE<< "2- Update Price" << endl;
    cout << BLUE<< "3- Update Stock" << endl;
    cout << BLUE<< "4- View Sorted Medicine Details" << endl;
    cout << BLUE<< "5- Display Medicines" << endl;
    cout << BLUE<< "6- Set Discounts "<< endl;
    cout << BLUE<<"7- Logout" << endl;
    cout << RED<<"Enter option: ";
    string option;
    cin >> option;
    return option;
}

char customerMenu()
{
    mainHeader();
    cout << GREEN<< "CUSTOMER MENU >" << endl;
    cout << BLUE<< "1- View Available Medicines" << endl;
    cout << BLUE<<"2- View Medicine Price" << endl;
    cout << BLUE<< "3- Categories" << endl;
    cout << BLUE<< "4- Recommended Medicines" << endl;
    cout << BLUE<< "5- Delivery" << endl;
    cout << BLUE<< "6- See Discounts "<< endl;
    cout << BLUE<<"7- Logout" << endl;
    cout << RED"Enter option: ";
    char option;
    cin >> option;
    return option;
}

string who()
{
    mainHeader();
    cout <<YELLOW<< "If you are Owner press U if you are Customer press C: ";
    char roleChoice;
    cin >> roleChoice;
    
    if (roleChoice == 'U' || roleChoice == 'u') {
        string userName, password;
        cout << "Enter Admin username: ";
        cin >> userName;
        cout << "Enter Admin password: ";
        cin >> password;

        // hardcoded admin credentials
        if (userName == "admin" && password == "admin123") {
            return "ADMIN";
        } else {
            cout << "Invalid admin credentials." << endl;
            return "wrong";
        }
    }
    else if (roleChoice == 'C' || roleChoice == 'c') {
        return "CUSTOMER";
    }
    else {
        cout << "Invalid choice." << endl;
        return "wrong";
    }
}

void addProduct()
{
    if (medicine_count < TOTAL_MEDICINE)
    {
        string name, wholeSale, price, stock;
        cout <<YELLOW<< "Enter medicine name: ";
        cin >> name;
        cout <<YELLOW "Enter wholesale price: ";
        cin >> wholeSale;
        cout <<YELLOW "Enter selling price: ";
        cin >> price;
        cout <<YELLOW "Enter stock: ";
        cin >> stock;

        nameA[medicine_count] = name;
        wholeSaleA[medicine_count] = wholeSale;
        priceA[medicine_count] = price;
        stockA[medicine_count] = stock;
        medicine_count++;
   fstream file;
    file.open("medicines.txt", ios::app);
    if (file.is_open())
    {
        file << name << "," << wholeSale << "," << price << "," << stock << endl;
        file.close();
        cout<<GREEN << "Medicine added successfully and saved to file." << endl;
    }
    else
    {
        cout<<RED << "Error: could not open file to save medicine." << endl;
    }
  }
    else
    {
    cout << "No more space to add medicine." << endl;
    }
}
void updatePrice()
{
    cout << "Enter medicine name to update price: ";
    string name;
    cin >> name;
    bool found = false;
    for (int i = 0; i < medicine_count; i++)
    {
        if (nameA[i] == name)
        {
            cout <<YELLOW<< "Enter new price: ";
            cin >> priceA[i];
            cout <<GREEN<< "Price updated successfully." << endl;
            found = true;
            break;
        }
    }
    if (!found)
    {
        cout <<RED<< "Medicine not found." << endl;
        return;
    }

    // rewrite the file with updated price
    ofstream out("medicines.txt");
    for (int i = 0; i < medicine_count; i++)
    {
        out << nameA[i] << "," << wholeSaleA[i] << "," << priceA[i] << "," << stockA[i] << endl;
    }
    out.close();
}

void updateStock()
{
    cout << "Enter medicine name to update stock: ";
    string name;
    cin >> name;
    bool found = false;
    for (int i = 0; i < medicine_count; i++)
    {
        if (nameA[i] == name)
        {
            cout <<YELLOW<< "Enter new stock: ";
            cin >> stockA[i];
            cout <<GREEN<< "Stock updated successfully." << endl;
            found = true;
            break;
        }
    }
    if (!found)
    {
        cout <<RED<< "Medicine not found." << endl;
        return;
    }

    // rewrite the file with updated stock
    ofstream out("medicines.txt");
    for (int i = 0; i < medicine_count; i++)
    {
        out << nameA[i] << "," << wholeSaleA[i] << "," << priceA[i] << "," << stockA[i] << endl;
    }
    out.close();
}

void viewPrice()
{
    // reload from file in case data changed
    ifstream in("medicines.txt");
    string line;
    medicine_count = 0;
    while (getline(in, line) && medicine_count < TOTAL_MEDICINE)
    {
        int pos1 = line.find(',');
        int pos2 = line.find(',', pos1 + 1);
        int pos3 = line.find(',', pos2 + 1);

        nameA[medicine_count] = line.substr(0, pos1);
        wholeSaleA[medicine_count] = line.substr(pos1 + 1, pos2 - pos1 - 1);
        priceA[medicine_count] = line.substr(pos2 + 1, pos3 - pos2 - 1);
        stockA[medicine_count] = line.substr(pos3 + 1);
        medicine_count++;
    }
    in.close();

    cout <<YELLOW<< "Enter medicine name to view price: ";
    string name;
    cin >> name;
    bool found = false;
    for (int i = 0; i < medicine_count; i++)
    {
        if (nameA[i] == name)
        {
            cout <<CYAN<< "Price of " << name << " is " << priceA[i] << endl;
            found = true;
            break;
        }
    }
    if (!found)
    {
        cout <<RED<< "Medicine not found." << endl;
    }
}

void sortedMedicine()
{
    // reload from file first
    ifstream in("medicines.txt");
    string line;
    medicine_count = 0;
    while (getline(in, line) && medicine_count < TOTAL_MEDICINE)
    {
        int pos1 = line.find(',');
        int pos2 = line.find(',', pos1 + 1);
        int pos3 = line.find(',', pos2 + 1);

        nameA[medicine_count] = line.substr(0, pos1);
        wholeSaleA[medicine_count] = line.substr(pos1 + 1, pos2 - pos1 - 1);
        priceA[medicine_count] = line.substr(pos2 + 1, pos3 - pos2 - 1);
        stockA[medicine_count] = line.substr(pos3 + 1);
        medicine_count++;
    }
    in.close();

    for (int i = 0; i < medicine_count - 1; i++)
    {
        for (int j = 0; j < medicine_count - i - 1; j++)
        {
            if (priceA[j] < priceA[j + 1])
            {
                swap(priceA[j], priceA[j + 1]);
                swap(nameA[j], nameA[j + 1]);
                swap(stockA[j], stockA[j + 1]);
                swap(wholeSaleA[j], wholeSaleA[j + 1]);
            }
        }
    }
}

void displayProduct()
{
    // reload from file
    ifstream in("medicines.txt");
    string line;
    medicine_count = 0;
    while (getline(in, line) && medicine_count < TOTAL_MEDICINE)
    {
        int pos1 = line.find(',');
        int pos2 = line.find(',', pos1 + 1);
        int pos3 = line.find(',', pos2 + 1);

        nameA[medicine_count] = line.substr(0, pos1);
        wholeSaleA[medicine_count] = line.substr(pos1 + 1, pos2 - pos1 - 1);
        priceA[medicine_count] = line.substr(pos2 + 1, pos3 - pos2 - 1);
        stockA[medicine_count] = line.substr(pos3 + 1);
        medicine_count++;
    }
    in.close();

    mainHeader();
    cout <<CYAN<< "Name\tWholesale\tPrice\tStock" << endl;
    for (int i = 0; i < medicine_count; i++)
    {
        cout << nameA[i] << "\t" << wholeSaleA[i] << "\t\t" << priceA[i] << "\t" << stockA[i] << endl;
    }
}

void displayMedicine()
{
    // reload from file
    ifstream in("medicines.txt");
    string line;
    medicine_count = 0;
    while (getline(in, line) && medicine_count < TOTAL_MEDICINE)
    {
        int pos1 = line.find(',');
        int pos2 = line.find(',', pos1 + 1);
        int pos3 = line.find(',', pos2 + 1);

        nameA[medicine_count] = line.substr(0, pos1);
        wholeSaleA[medicine_count] = line.substr(pos1 + 1, pos2 - pos1 - 1);
        priceA[medicine_count] = line.substr(pos2 + 1, pos3 - pos2 - 1);
        stockA[medicine_count] = line.substr(pos3 + 1);
        medicine_count++;
    }
    in.close();

    mainHeader();
    cout <<CYAN<< "Medicines Available: " << endl;
    for (int i = 0; i < medicine_count; i++)
    {
        cout <<CYAN<< i + 1 << ". " << nameA[i] << endl;
    }
}
void hardcodedCategories()
{
    mainHeader();
    cout << "Categories:" << endl;
    cout << "1. Painkillers" << endl;
    cout << "2. Antibiotics" << endl;
    cout << "3. Multivitamins" << endl;
    cout << "4. Skin Care" << endl;
}

void recommendedMedicines()
{
    mainHeader();
    cout << "Recommended Medicines:" << endl;
    cout << "- Panadol" << endl;
    cout << "- Augmentin" << endl;
    cout << "- Neurobion" << endl;
}

void delivery()
{
    mainHeader();
    cout << "Enter your delivery address: ";
    string address;
    cin.ignore();
    getline(cin, address);
    cout << "Your order will be delivered to: " << address << endl;
}
void Discounts()
{
    system("cls");
    mainHeader();
    cout << "Enter medicine name to set discount: ";
    string name;
    cin >> name;

bool found = false;
for (int i = 0; i < medicine_count; i++)
{
    if (nameA[i] == name)
     {
        cout << "Enter discount percentage (e.g. 10%): ";
        string discount;
        cin >> discount;
        // save to file
        fstream write;
        write.open("Discounted Medicines.txt", ios::app);
        write << name << "," << discount << endl;
        write.close();

        cout << "Discount saved successfully for " << name << endl;
        found = true;
        break;
        }
    }

    if (!found)
    {
        cout << "Medicine not found!" << endl;
    }
}
void SeeDiscount()
{
    system("cls");
    mainHeader();
    cout << "Discounted Medicines:" << endl;
    cout << "-----------------------------------------" << endl;
    cout << "Name\t\tDiscount" << endl << endl;

    fstream read;
    read.open("DiscountFile.txt", ios::in);
    {
     cout << "No discounts available yet." << endl;
     return;
    }

    string record;
    bool anyDiscount = false;

    while (getline(read, record))
    {
     string name;
     string discount;
     int commaPos = record.find(',');
     if (commaPos != string::npos)
      {
        name = record.substr(0, commaPos);
        discount = record.substr(commaPos + 1);
        cout << name << "\t" << discount << endl;
        anyDiscount = true;
      }
    }

    if (!anyDiscount)
    {
     cout << "No discounts available at the moment." << endl;
    }

    read.close();
}
