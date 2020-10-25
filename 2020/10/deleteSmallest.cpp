void delete_Smallest_Node_From_Linked_List() {
	if (head == nullptr)
		return;
	if (head->link == nullptr)
	{
		delete head;
		head = nullptr;
		size -= 1;
		return;
	}
	nodeType* curr = head;
	int smallestNum = curr->info;
	nodeType* smallestPrev = curr;
	//Intentional: smallestPtr must be initialized in order to attempt to detect node #1.
	//This is fine since we detect changes to the minimum constant starting at curr (Node #2).
	nodeType* smallestPtr = curr;
	nodeType* smallestNext = curr->link->link;

	//Begin at node 2.
	nodeType* prev = curr;
	curr = curr->link;
	while (curr != nullptr) {
		//if found new smallest candidate:
		if (curr->info < smallestNum) {
			smallestNum = curr->info;
			smallestPrev = prev;
			smallestPtr = curr;
			smallestNext = curr->link;
		}
		prev = curr;
		curr = curr->link;
	}
	size -= 1;
	if (smallestPtr == head) {
		nodeType* prevHead = head;
		head = head->link;
		delete prevHead;
		return;
	}
	smallestPrev->link = smallestNext;
	delete smallestPtr;
}