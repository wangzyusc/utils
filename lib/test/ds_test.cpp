#include "../header/data_structure.hpp"
#include "../header/io.hpp"

void test_double_linked_list(){
	DoubleLinkedList<int> list = readDoubleLinkedList<int>();
	printDoubleLinkedList<int>(list);
}

void test_double_list_node(){
	DoubleListNode<int>* node = new DoubleListNode<int>(0);
	delete node;
}

int main(void){
	test_double_linked_list();
	test_double_list_node();
	return 0;
}
