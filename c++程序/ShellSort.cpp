void ShellSort(int* a,int length)
{
	int i,j,h=1;
	while(h<length/3)
	h=3*h+1;
	while(h>=1)
	{
		for(i=h;i<length;i++)                          //�±�i֮������ݸ���С������h 
		{
			for(j=i;j>=h&&a[j]<a[j-h];j-=h)             //ִ�в������� 
			{
				int temp=a[j];
				a[j]=a[j-h];
				a[j-h]=temp;
			}
		}
		h/=3;
	}
}
