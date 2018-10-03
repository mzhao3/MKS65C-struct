#include <stdio.h>
#include <string.h>
#include <time.h>

struct beyblade {char name[10]; unsigned int size; char color[10];};

struct beyblade construct_beyblade(char * new_name, char * new_color) {
	//creates a new beyblade named Carl woth random size and color of choice

	struct beyblade Carl;

	strcpy(Carl.name, new_name);
	
	strcpy(Carl.color, new_color);
	
	Carl.size = rand() % 100;
	
	return Carl;
}

int print_beyblade(struct beyblade instance ) {
	//prints out the name, size, and color

	printf("Name: %s\n", instance.name);
	printf("Size: %dmm\n", instance.size);
	printf("Colr: %s\n", instance.color);
	printf("\n");
	return 0;
}

int beyblade_change_name(int place, char letter, struct beyblade * instance) {
	//changes name to input name

	char * x = instance->name;
	while(place--) {x++;}

	*x = letter;

	return 0;
}

int beyblade_change_size(int add, struct beyblade * instance ) {
	//changes size by amount of mm input

	instance->size += add;
	return 0;
}

int beyblade_change_color(char * new_color, struct beyblade * instance ) {
	//chanegs color of beyblade input to the input color

	strcpy(instance->color, new_color);
	return 0;
}

int main()
{
	printf("LET IT RIP!\n");

	//seed the random number
	srand(time(NULL));

	//create a new beyblade called Spinner
	struct beyblade Spinner = construct_beyblade("Carl","Grey");
	
	//ref is a pointer that holds the adress of Spinner
	struct beyblade * ref = &Spinner;

	//print Spinner
	print_beyblade(Spinner);

	//alter the name of Spinner (10 character max)
	beyblade_change_name(3,'b', ref);
	printf("Carl->Carb\n");

	//name should now be James
	print_beyblade(Spinner);
	
	//alter the color of Spinner (10 character max)
	beyblade_change_color("Blue", ref);
	printf("Grey->Blue\n");
	
	//color should now be "Blue"
	print_beyblade(Spinner);
	
	//alter the size of Spinner
	beyblade_change_size(8, ref);
	printf("add  eight\n");
	
	//size shoule be 8 larger
	print_beyblade(Spinner);
	return 0;
}