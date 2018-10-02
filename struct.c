#include <stdio.h>
#include <string.h>
#include <time.h>

struct beyblade {char name[10]; unsigned int size; char color[10];};

struct beyblade construct_beyblade(char * color_input) {
	struct beyblade Carl;
	strcpy(Carl.name, "Carl");
	strcpy(Carl.color, color_input);
	//Carl.name = "Carl";
	Carl.size = rand() % 100;
	//Carl.color = color_input;
	return Carl;
}

int print_beyblade(struct beyblade gene) {
	printf("Name: %s\n", gene.name);
	printf("Size: %dmm\n", gene.size);
	printf("Colr: %s\n", gene.color);
	printf("\n");
	return 0;
}

int beyblade_change_size(int add, struct beyblade* ralph) {
	ralph->size += add;
}

int beyblade_change_color(char * color_input, struct beyblade * john) {
	strcpy(john->color, color_input);
}

int main()
{
	struct beyblade Maggie = construct_beyblade("Grey");
	struct beyblade * ref = &Maggie;

	print_beyblade(Maggie);
	
	beyblade_change_color("Blue", ref);
	
	print_beyblade(Maggie);
	
	beyblade_change_size(1, ref);
	
	print_beyblade(Maggie);
	return 0;
}