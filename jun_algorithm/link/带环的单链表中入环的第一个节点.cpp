//��֪һ���������д��ڻ�������뻷�еĵ�һ���ڵ�

ListNode* GetFirstNodeInCircle(ListNode* phead)
{
	if(phead == NULL || phead->next == NULL)
	{
		return NULL;
	}

	ListNode* pfast = phead;
	ListNode* pslow = phead;
	//���ж��Ƿ���ڻ�
	while(pfast != NULL && pfast->next != NULL)
	{
		pslow = pslow->next;
		pfast = pfast->next->next;
		if(pslow == pfast)
			break;
	}
	if(pfast == NULL || pfast->next == NULL)
		return NULL;

	//������ڻ�������ָ�붼��ͬ�����ٶ�ǰ����������Ϊ��һ���ڵ�
	pfast = phead;
	while(pslow != pfast)
	{
		pslow= pslow->next;
		pfast = pfast->next;
	}
	return pslow;
}

//����һ����Ҫ��ɾ�������еĽڵ�
typedef boolk (*remove_fn)(ListNode* node);

ListNode* remove_if(ListNode* head,remove_fn rm)
{
	for(ListNode* prev= NULL,*curr = head;curr != NULL)
	{
		ListNode* next = curr->next;
		if(rm(curr))
		{
			if(prev)
				prev->next = next;
			else
				head= next;
			delete curr;
		}
		else
			prev= curr;
		curr = next;
	}
	return head;
}

// ������(ʹ�ö���ָ��ɾ���������еĽڵ�)��Linux�ں˴��룩
void remove_if(ListNode** head,remove_if rm)
{
	for(ListNode** curr = head;*curr;)
	{
		ListNode* entry = *curr;
		if(rm(entry))
		{
			*curr = entry->next;
			delete entry;
		}
		else
			curr = &entry->next;
	}
}
