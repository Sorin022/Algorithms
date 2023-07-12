void split(ptr head, ptr* front, ptr* back) {
    Node* by2;
    Node* by1;
    slow = head;
    fast = head->link;

    while (by2 != nullptr) {
        by2 = by2->link;
        if (by2 != nullptr) {
            by1 = by1->link;
            by2 = by2->link;
        }
    }

    *front = head;
    *back = by1->link;
    by1->link = nullptr;
}

ptr Merge(ptr l1, ptr l2) {
  if (l1 == NULL) {
    return l2;
  }

  if (l2 == NULL) {
    return l1;
  }

  ptr mergeValue;

  if (l1->data < l2->data) {
    mergeValue = l1;
    mergeValue->link = Merge(l1->link, l2);
  }
  else {
    mergeValue = l2;
    mergeValue->link = Merge(l1, l2->link);
  }

  return mergeValue;
}


ptr MergeSort(ptr head){
  if(head==NULL || head->link==NULL){
    return head;
  }

  ptr middle = Middle(head);

  ptr l1 = head;
  ptr l2 = middle->link;

  middle->link = NULL;

  l1 = MergeSort(l1);
  l2 = MergeSort(l2);

  return Merge(l1, l2);

}