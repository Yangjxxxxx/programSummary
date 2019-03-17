void SelectionSort(int* a,int length)
{
	int i,j,min,temp;
	for(i=0;i<length;i++)
	{
		min=i;
		for(j=i+1;j<length;j++)
		{
			if(a[min]>a[j])
			min=j;
		}
		temp=a[i];
		a[i]=a[min];
		a[min]=temp;
	}
}
