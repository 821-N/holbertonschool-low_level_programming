#include <stdio.h>
#include <string.h>
#include <math.h>

//print array
void pa(short array[], int len){
	int i;
	for(i=0;i<len;i++)
		printf("%d\t",array[i]);
	printf("\n");
}

//print array
void pa2(char *array[], int len){
	int i;
	for(i=0;i<len;i++)
		printf("%s\t",array[i]);
	printf("\n");
}

//print array
void pa3(double array[], int len){
	int i;
	for(i=0;i<len;i++)
		printf("%f\t",array[i]);
	printf("\n");
}

// Counting sort 2
// @array1 - array of keys (ints)
// @array2 - values (any type)
// @size - size of values in @array2
// @length - length of arrays
void cs2(void *data,size_t size,size_t length,size_t(*value)(void*,size_t)){
	//get keys, and range	
	size_t i,min,max,values[length];
	min=max=values[0]=(*value)(data,0);
	for(i=0;i<length;i++){
		size_t x=values[i]=(*value)(data,i);
		if(x<min)
			min=x;
		else if(x>max)
			max=x;
	}
	size_t range=max-min+1;
	//count:
	size_t counts[range];
	memset(counts,0,sizeof counts);
	for(i=0;i<length;i++)
		++counts[values[i]-min];
	//get offsets
	size_t p=0;
	for(i=0;i<range;i++){
		size_t count=counts[i];
		counts[i]=p;
		p+=count;
	}
	
	//Sort the data
	char temp[length*size];
	for(i=0;i<length;i++)
		memcpy(temp+counts[values[i]-min]++*size, data+i*size, size);
	memcpy(data,temp,length*size);
}

size_t length(char *value[],size_t i){
	return strlen(value[i]);
}

size_t value(short value[],size_t i){
	return value[i];
}

size_t sort_abs(double value[],size_t i){

//	return 1	

	return value[i]<0;
}

int main(){
	char *test2[10] = {"","something","test","AAAAAA","123","..","c","very long string","test","a"};
	short test[10] = {698,123,6,1,5,2,2,2,34,123};
	double test3[10] = {3.14159,-1e9,2e11,58329432,-40,14522,0,-0.0,36,1e308*2};
	
	pa(test,10);
	cs2(test,sizeof(test[0]),10,value);
	pa(test,10);

	pa2(test2,10);
	cs2(test2,sizeof(test2[0]),10,length);
	pa2(test2,10);

	pa3(test3,10);
	cs2(test3,sizeof(test3[0]),10,sort_abs);
	pa3(test3,10);


}
