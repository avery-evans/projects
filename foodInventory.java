import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;
import java.util.Scanner;


class FoodInventory {
    String foodName;
    String expirationDate;


    public FoodInventory(String foodName, String expirationDate) {
        this.foodName = foodName;
        this.expirationDate = expirationDate;
    }


    public String getFoodName() {
        return foodName;
    }


    public String getExpirationDate() {
        return expirationDate;
    }
}


class Food {
    private List<FoodInventory> foodItems;


    public Food() {
        foodItems = new ArrayList<>();
        addInitialItems();
    }


    private void addInitialItems() {
        // Initialize with an array of food items
        String[][] initialItems = {
            {"apple", "April 20, 2024"},
            {"orange", "April 20, 2024"},
            {"bread", "March 27, 2024"},
            {"milk", "April 2, 2024"},
            {"sugar", "May 9, 2025"},
            {"eggs", "April 2, 2025"},
            {"cereal", "June 26, 2025"},
            {"jelly", "December 7, 2024"},
            {"chicken", "April 27, 2024"},
            {"butter", "May 17, 2024"},
            {"green pepper", "June 26, 2024"},
            {"red pepper", "April 27, 2024"}
        };


        for (String[] item : initialItems) {
            foodItems.add(new FoodInventory(item[0], item[1]));
        }
    }


    public void addItem(String foodName, String expirationDate) {
        foodItems.add(new FoodInventory(foodName, expirationDate));
    }


    public void display() {
        System.out.println("Current inventory list:");
        for (FoodInventory item : foodItems) {
            System.out.println(item.getFoodName() + " expiration date: " + item.getExpirationDate());
        }
    }


    public void removeItem(String foodName) {
        Iterator<FoodInventory> iterator = foodItems.iterator();
        while (iterator.hasNext()) {
            FoodInventory item = iterator.next();
            if (item.getFoodName().equalsIgnoreCase(foodName)) {
                iterator.remove();
                System.out.println(foodName + " item has been removed.");
                return;
            }
        }
        System.out.println(foodName + " item could not be found.");
    }
}


public class App {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Food myFood = new Food();
        int choice;


        do {
            System.out.println("\nPlease choose an option:");
            System.out.println("1. Add an item");
            System.out.println("2. Remove an item");
            System.out.println("3. Display inventory");
            System.out.println("4. Exit");
            System.out.print("Enter your choice: ");
            choice = scanner.nextInt();
            scanner.nextLine(); 


            switch (choice) {
                case 1: 
                    System.out.println("Enter the name and expiration date of the item to add (Ex: apple January 18 2024): ");
                    String[] addItemInput = scanner.nextLine().split(", ");
                    if (addItemInput.length == 2) {
                        myFood.addItem(addItemInput[0], addItemInput[1]);
                        System.out.println(addItemInput[0] + " has been added.");
                    } else {
                        System.out.println("Please enter in the correct format.");
                    }
                    break;


                case 2: // Remove an item
                    System.out.println("Enter the name of the item to remove: ");
                    String removeItemName = scanner.nextLine();
                    myFood.removeItem(removeItemName);
                    break;


                case 3: // Display inventory
                    myFood.display();
                    break;


                case 4: // Exit
                    System.out.println("Exiting the program...");
                    break;


                default:
                    System.out.println("Invalid choice. Please enter 1, 2, 3, or 4.");
            }
        } while (choice != 4);


        scanner.close();
    }
}
