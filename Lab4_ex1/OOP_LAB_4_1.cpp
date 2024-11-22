#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Product Class
class Product 
{
private:
    string name;
    double price;
    bool isOnPromotion;

public:
    Product(string name, double price, bool isOnPromotion = false)
        : name(name), price(price), isOnPromotion(isOnPromotion) {}

    string getName() const { return name; }
    double getPrice() const { return price; }
    bool getIsOnPromotion() const { return isOnPromotion; }

    void setName(const string& newName) { name = newName; }
    void setPrice(double newPrice) { price = newPrice; }
    void setIsOnPromotion(bool promotion) { isOnPromotion = promotion; }

    void display() const 
    {
        cout << "Product: " << name << ", Price: $" << price<< ", Promotion: " << (isOnPromotion ? "Yes" : "No") << endl;
    }
};

// Category Class
class Category 
{
private:
    string name;
    vector<Product> products;

public:
    Category(const string& name) : name(name) {}

    string getName() const { return name; }

    void addProduct(const Product& product) 
    {
        products.push_back(product);
    }

    void removeProduct(const string& productName) 
    {
        for (auto it = products.begin(); it != products.end(); ++it) 
        {
            if (it->getName() == productName) 
            {
                products.erase(it);
                cout << "Product " << productName << " removed from category " << name << "." << endl;
                return;
            }
        }
        cout << "Product " << productName << " not found in category " << name << "." << endl;
    }

    void updateProduct(const string& productName, double newPrice, bool isOnPromotion) 
    {
        for (auto& product : products) 
        {
            if (product.getName() == productName) 
            {
                product.setPrice(newPrice);
                product.setIsOnPromotion(isOnPromotion);
                cout << "Product " << productName << " updated." << endl;
                return;
            }
        }
        cout << "Product " << productName << " not found in category " << name << "." << endl;
    }

    void displayProducts() const 
    {
        cout << "Category: " << name << endl;
        for (const auto& product : products) 
        {
            product.display();
        }
    }

    vector<Product> getProducts() const 
    {
        return products;
    }
};

// OnlineShop Class
class OnlineShop {
private:
    vector<Category> categories;

public:
    void addCategory(const Category& category) 
    {
        categories.push_back(category);
        cout << "Category " << category.getName() << " added to shop." << endl;
    }

    void removeCategory(const string& categoryName) 
    {
        for (auto it = categories.begin(); it != categories.end(); ++it) 
        {
            if (it->getName() == categoryName) 
            {
                categories.erase(it);
                cout << "Category " << categoryName << " removed from shop." << endl;
                return;
            }
        }
        cout << "Category " << categoryName << " not found in shop." << endl;
    }

    void displayAllProducts() const 
    {
        cout << "All Products in Shop:" << endl;
        for (const auto& category : categories) 
        {
            category.displayProducts();
        }
    }

    void displayPromotionalProducts() const 
    {
        cout << "Promotional Products in Shop:" << endl;
        for (const auto& category : categories) 
        {
            for (const auto& product : category.getProducts()) 
            {
                if (product.getIsOnPromotion())
                {
                    product.display();
                }
            }
        }
    }

    void searchProduct(const string& name, double minPrice, double maxPrice) const 
    {
        cout << "Search Results:" << endl;
        for (const auto& category : categories) 
        {
            for (const auto& product : category.getProducts()) 
            {
                if (product.getName().find(name) != string::npos &&product.getPrice() >= minPrice && product.getPrice() <= maxPrice) 
                {
                    product.display();
                }
            }
        }
    }
};

// Main Function
int main() 
{
    OnlineShop shop;

    // Create categories
    Category electronics("Electronics");
    Category clothing("Clothing");

    // Create products
    Product laptop("Laptop", 1200.00);
    Product smartphone("Smartphone", 800.00, true);
    Product tshirt("T-Shirt", 20.00);
    Product jeans("Jeans", 50.00, true);

    // Add products to categories
    electronics.addProduct(laptop);
    electronics.addProduct(smartphone);
    clothing.addProduct(tshirt);
    clothing.addProduct(jeans);

    // Add categories to shop
    shop.addCategory(electronics);
    shop.addCategory(clothing);

    // Display all products
    shop.displayAllProducts();

    // Display promotional products
    shop.displayPromotionalProducts();

    // Search for products based on criteria
    cout << "\nSearching for products with name containing 'Shirt' and price between $10 and $30:" << endl;
    shop.searchProduct("Shirt", 10, 30);

    // Update a product
    clothing.updateProduct("T-Shirt", 18.00, true);

    // Remove a product
    electronics.removeProduct("Smartphone");

    // Display updated product list
    cout << "\nUpdated Product List:" << endl;
    shop.displayAllProducts();

    return 0;
}
