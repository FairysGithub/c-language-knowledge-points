#include<stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	int key;//���ҵ���
	scanf("%d",&key);
	int low=0,high=n-1,num=1;
	while(low<=high){
		int mid=(low+high)/2;
		if(key==a[mid]){
			printf("���ҳɹ�!����%d��!a[%d]=%d",num,mid,key);
			break;
		}
		else if(key<a[mid]){
			high=mid-1;
		}else{
			low=mid+1;
		}
		num++;
	}
}
