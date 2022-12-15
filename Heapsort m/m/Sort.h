template< class T >
void downHeap(T a[], long k, long n) /*процедура просеивани€ следующего элемента. 
									 ƒо процедуры: a[k+1]...a[n]  - пирамида 
									 ѕосле:  a[k]...a[n]  - пирамида */
{      
	T new_elem;
	long child;
	new_elem = a[k];

	while(k <= n/2) // пока у a[k] есть дети 
	{           
		child = 2*k;

		if( child < n && a[child] < a[child+1] ) //  выбираем большего сына 
			child++;
		if( new_elem >= a[child] ) 
			break; 
		// иначе 
		a[k] = a[child];        // переносим сына наверх 
		k = child;
	}
	a[k] = new_elem;
}

template< class T >
void Sort(T *a, int n) 
{
	int i;
	T temp;
	for(i = n / 2 - 1; i >= 0; --i) // строим пирамиду
		downHeap(a, i, n-1);
	for(i=n-1; i > 0; --i) // теперь a[0]...a[size-1] пирамида 
	{	// мен€ем первый с последним 
		temp = a[i]; 
		a[i] = a[0]; 
		a[0] = temp;
		downHeap(a, 0, i-1); // восстанавливаем пирамидальность a[0]...a[i-1] 
	}
}
