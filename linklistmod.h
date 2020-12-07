//BenjaminKramer
//12-7-2020

//Header file for the LinkedList
//illustration utilizing an 
//insertAtPosition and deleteAtPosition
#include <iostream>

using namespace std;

//Making the ListItem configurations
class ListItem {
  
  private:

    const char* item;
    ListItem* next = nullptr;
    
  public:
    
    ListItem(const char *newItem) {
      item = newItem;
      next = nullptr;
    }

    ListItem* nextItem() {
      return next;
    }

    void setNextItem(ListItem* new_next) {
      next = new_next;
    }

    const char* view() {
      return item;
    }

};

//Creating the LinkedList
class LinkedList {
private:

    ListItem* first_item;
    ListItem* previous_item;
    int list_length;
  
    void deleteItem(ListItem* parent, ListItem* item) {
      parent->setNextItem(item->nextItem());
      delete item;
    }

  public:

    LinkedList(const char *newItem) {
      first_item = new ListItem(newItem);
      list_length = 1;
    }

    //addListItem
    void addListItem(const char *newItem) {
      ListItem* new_item = new ListItem(newItem);
      ListItem* current_item = first_item;
      ListItem* next_item = first_item->nextItem();
      while (next_item != nullptr) {

        current_item=next_item;
        next_item = current_item->nextItem();
   
      }
      current_item->setNextItem(new_item);
      list_length += 1;
    }
   
	 //insertAtPosition
   void insertAtPosition(const char* newItem, int index) {
		ListItem* new_item = new ListItem(newItem);
		ListItem* current_item = first_item;
		ListItem* next_item = first_item->nextItem();
		ListItem* swap_item;
		int itemIndex = 0;
		if (index <= list_length && index > -1) {
			while (current_item != nullptr) {
				if (itemIndex == 0 && index == 0) {
					swap_item = first_item;
					first_item = new_item;
					current_item = first_item;
					current_item->setNextItem(swap_item);
				}
				else if (itemIndex == index) {
					swap_item = current_item;
					current_item = new_item;
					current_item->setNextItem(swap_item);
					previous_item->setNextItem(current_item);
				}
				previous_item = current_item;
				next_item = current_item->nextItem();
				current_item = next_item;
				itemIndex += 1;
			}
			list_length += 1;
		}
		else {
			std::cout << "Position chosen is out of bounds." << std::endl;
		}
  }

//deleteAtPosition
	void deleteAtPosition(int index) {
		ListItem* current_item = first_item;
		ListItem* next_item = first_item->nextItem();
		ListItem* swap_item;
		int itemIndex = 0;
		if (index <= list_length && index > -1) {

		while (current_item != nullptr) {
			if (itemIndex == 0 && index == 0) {
				swap_item = first_item;
				first_item = first_item->nextItem();
				break;
			}
			else if (itemIndex == index) {
				previous_item->setNextItem(current_item->nextItem());
				break;
			}
			previous_item = current_item;
			current_item = next_item;
			next_item = current_item->nextItem();
			itemIndex += 1;
		}
		list_length -= 1;
		}
		else {
			std::cout << "Index chosen is out of bounds." << std::endl;
		}
	}
    int length() {
      return list_length;
    }

    void outputLength() {
      std::cout << length() << std::endl;
    }
    //prints the list with all items (new and old)
    void outputList() {
      std::cout << first_item->view() << std::endl;
      ListItem* next_item = first_item->nextItem();
      while (next_item != nullptr) {
        std::cout << next_item->view() << std::endl;
        next_item = next_item->nextItem();
      }
    }
};
