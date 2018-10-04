#include <stdio.h>
#include <string.h>
#include <time.h>

const char *colors[] = {"Yellow","Green","Blue", "Red", "Black", "Orange", "White", "Pink", "Brown"};
const char *names[] = {"Carl", "Scott", "Pegasus", "Sagittario", "Leone", "Libra", "Donald"};

struct beyblade {char name[15]; unsigned int size; char color[10];};

	//creates a new beyblade named Carl with random size and color
struct beyblade construct_beyblade() {

	srand(time(NULL));
	//seed the random number

	struct beyblade Carl;
	//printf("%s\n", names[ (rand() % 7)]);
	strcpy(Carl.name, names[ (rand() % 7)]);

	strcpy(Carl.color, colors[ (rand() % 9)]);

	Carl.size = rand() % 100;

	return Carl;
}

	//prints out the name, size, and color
int print_beyblade(struct beyblade instance) {

	printf("Name: %s\n", instance.name);
	printf("Size: %dmm\n", instance.size);
	printf("Colr: %s\n", instance.color);
	printf("\n");
	return 0;
}

 // changes specified letter at specified location in the name
int beyblade_change_name(int place, char letter, struct beyblade * instance) {

	char * x = instance->name;
	while(place--) {x++;}

	*x = letter;

	return 0;
}

	//changes size by amount of mm input
int beyblade_change_size(int add, struct beyblade * instance ) {

	instance->size += add;
	return 0;
}

 //changes color of beyblade input to the input color
int beyblade_change_color(char * new_color, struct beyblade * instance ) {

	strcpy(instance->color, new_color);
	return 0;
}

int main()
{
	printf("\n===========================================\n");
	printf("LET IT RIP!\n\n");

	//create a new beyblade called Spinner
	struct beyblade Spinner = construct_beyblade();

	//ref is a pointer that holds the adress of Spinner
	struct beyblade * ref = &Spinner;

	printf("Original beyblade\n");
	//print Spinner
	print_beyblade(Spinner);

	//alter the name of Spinner (10 character max)
	beyblade_change_name(3,'b', ref);
	printf("Change the fourth letter to b\n");

	//name should now be James
	print_beyblade(Spinner);

	//alter the color of Spinner (10 character max)
	beyblade_change_color("Blue", ref);
	printf("Change color to blue\n");

	//color should now be "Blue"
	print_beyblade(Spinner);

	//alter the size of Spinner
	beyblade_change_size(8, ref);
	printf("Add eight to size\n");

	//size shoule be 8 larger
	print_beyblade(Spinner);
	return 0;
}
