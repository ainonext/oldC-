template< class T >
void downHeap(T a[], long k, long n) /*��������� ����������� ���������� ��������. 
									 �� ���������: a[k+1]...a[n]  - �������� 
									 �����:  a[k]...a[n]  - �������� */
{      
	T new_elem;
	long child;
	new_elem = a[k];

	while(k <= n/2) // ���� � a[k] ���� ���� 
	{           
		child = 2*k;

		if( child < n && a[child] < a[child+1] ) //  �������� �������� ���� 
			child++;
		if( new_elem >= a[child] ) 
			break; 
		// ����� 
		a[k] = a[child];        // ��������� ���� ������ 
		k = child;
	}
	a[k] = new_elem;
}

template< class T >
void Sort(T *a, int n) 
{
	int i;
	T temp;
	for(i = n / 2 - 1; i >= 0; --i) // ������ ��������
		downHeap(a, i, n-1);
	for(i=n-1; i > 0; --i) // ������ a[0]...a[size-1] �������� 
	{	// ������ ������ � ��������� 
		temp = a[i]; 
		a[i] = a[0]; 
		a[0] = temp;
		downHeap(a, 0, i-1); // ��������������� ��������������� a[0]...a[i-1] 
	}
}
