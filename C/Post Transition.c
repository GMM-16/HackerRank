/*
We live in a big country. This country has towns_count towns in it. Each town has some post offices in which packages are stored and transferred.
Post offices have different inner structure. Specifically, each of them has some limitations on the packages it can store - their weight should be between min_weight and max_weight inclusively, where min_weight and max_weight are fixed for each office.
Packages are stored in some order in the office queue. That means, that they are processed using this order when sending and receiving.
Sometimes two post offices, even in different towns, may organize the following transaction: the first one sends all its packages to the second one. The second one accepts the packages that satisfy the weight condition for the second office and rejects all other ones. These rejected packages return to the first office back and are stored in the same order they were stored before they were sent. The accepted packages move to the tail of the second office's queue in the same order they were stored in the first office.
You should process several queries in your program. You'll be provided with structures package, post_office and town. in order to complete this task, you should fill the following functions:
print_all_packages - given the town t, print all packages in this town. They should be printed as follows:

Town_name:
    0:
        id_0
        id_1
        ...
    1:
        id_2
        id_3
        ...
    ...

where 0, 1 etc are the numbers of post offices and id0, id1 ... are the ids of packages from the 0th post office in the order of its queue, id2, id3 are from the 1st one etc. There should be one '\t' symbol before post office numbers and two '\t' symbols before the ids.
send_all_acceptable_packages - given the towns source and target and post office indices source_office_index and target_office_index, manage the transaction described above between the post office #source_office_index in town source and the post office #target_office_index in town target.
town_with_most_packages - given all towns, find the one with the most number of packages in all post offices altogether. If there are several of them, find the first one from the collection towns.
find_town - given all towns and a string name, find the town with the name name. It's guaranteed that the town exists.

Input Format
First line of the input contains a single integer towns_count. towns_count blocks follow, each describing a town.
Every town block contains several lines. On the first line there is a string town_name - the name of the town. On the second line there is an integer offices_count - the number of the offices in the town. offices_count blocks follow then, each describing an office.
Every office block also contains several lines. On the first line there are three integers separated by single spaces: packages_count (the number of packages in the office), min_weight and max_weight (described above). packages_count blocks follow, each describing a package.
Every package block contains exactly two lines. On the first line there is a string id which is an id of the package. On the second line there is an integer weight which is the weight of the package.
Then, there is a single integer queries on the line which is the number of queries. queries blocks follow, each describing a query.
Every query block contains several lines. On the first line there is an integer 1, 2 or 3. If this integer is 1, on the second line there is a string town_name - the name of town for which all packages should be printed. If this integer is 2, on the second line there are string source_name, integer source_office_index, string target_name and integer target_office_index separated by single spaces. That means transactions between post office #source_office_index in the town source_name and post office #target_office_index in the town target_name should be processed.
If the integer is 3, no lines follow and the town with the most number of packages should be found.

Constraints
All integer are between 0 and 10
towns_count > 0, offices_count > 0.
All strings have length <= 5
All towns' names have only uppercase english letters and are unique.
All packages' ids have only lowercase english letters and are unique.
For each post office,min_weight <= max_weight.
All queries are valid, that means, towns with the given names always exist, post offices with the given indices always exist.

Output Format
For queries of type 1, print all packages in the format provided in the problem statement. For queries of type 3, print "Town with the most number of packages is townname" on a separate line.
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX_STRING_LENGTH 6

struct package
{
	char* id;
	int weight;
};

typedef struct package package;

struct post_office
{
	int min_weight;
	int max_weight;
	package* packages;
	int packages_count;
};

typedef struct post_office post_office;

struct town
{
	char* name;
	post_office* offices;
	int offices_count;
};

typedef struct town town;

void print_all_packages(town t) 
{
    printf("%s:\n",t.name);
    for(int i=0;i<t.offices_count;i++)
    {
        printf("\t%d:\n",i);
        for(int office=0;office<t.offices[i].packages_count;office++)
        {
            printf("\t\t%s\n",t.offices[i].packages[office].id);
        }
    }
}

void send_all_acceptable_packages(town* source, int source_office_index, town* target, int target_office_index) 
{	
    post_office *src=source->offices+source_office_index;
    post_office *src_1=target->offices+target_office_index;
    package temple[src->packages_count];
    int temple_size=0;
    for(int i=0;i<src->packages_count;)
    {
        if(src->packages[i].weight>=src_1->min_weight && src->packages[i].weight<=src_1->max_weight)
           {
            temple[temple_size++]=src->packages[i];
            for(int j=i;j<src->packages_count-1;j++)
            {
                src->packages[j]=src->packages[j+1]; 
            } 
            src->packages_count--;
        }
        else i++;
    }
    src_1->packages=realloc(src_1->packages, 
    (src_1->packages_count+temple_size)*sizeof(package));
    for(int i=0;i<temple_size;i++)
    {
        src_1->packages[src_1->packages_count++]=temple[i];
    }
}

town town_with_most_packages(town* towns, int towns_count) 
{
    town s_max=*towns; int max=0;
    for(int i=0;i<towns->offices_count;i++)
    {
        max+=towns->offices[i].packages_count;
    }
    towns++;towns_count--;
    while(towns_count)
    {
        int sum=0;
        for(int i=0;i<towns->offices_count;i++)
        {
            sum+=towns->offices[i].packages_count;
        }
        if(sum>max)
        {
            max=sum;
            s_max=*towns;
        }
        towns++;towns_count--;
    }
    return s_max;
}

town* find_town(town* towns, int towns_count, char* name) 
{
    while(towns_count){
        if(!strcmp(towns->name,name))
        {
            return towns;
        }
        towns++; towns_count--;
    }
    return NULL;
}

int main()
{
	int towns_count;
	scanf("%d", &towns_count);
	town* towns = malloc(sizeof(town)*towns_count);
	for (int i = 0; i < towns_count; i++) {
		towns[i].name = malloc(sizeof(char) * MAX_STRING_LENGTH);
		scanf("%s", towns[i].name);
		scanf("%d", &towns[i].offices_count);
		towns[i].offices = malloc(sizeof(post_office)*towns[i].offices_count);
		for (int j = 0; j < towns[i].offices_count; j++) {
			scanf("%d%d%d", &towns[i].offices[j].packages_count, &towns[i].offices[j].min_weight, &towns[i].offices[j].max_weight);
			towns[i].offices[j].packages = malloc(sizeof(package)*towns[i].offices[j].packages_count);
			for (int k = 0; k < towns[i].offices[j].packages_count; k++) {
				towns[i].offices[j].packages[k].id = malloc(sizeof(char) * MAX_STRING_LENGTH);
				scanf("%s", towns[i].offices[j].packages[k].id);
				scanf("%d", &towns[i].offices[j].packages[k].weight);
			}
		}
	}
	int queries;
	scanf("%d", &queries);
	char town_name[MAX_STRING_LENGTH];
	while (queries--) {
		int type;
		scanf("%d", &type);
		switch (type) {
		case 1:
			scanf("%s", town_name);
			town* t = find_town(towns, towns_count, town_name);
			print_all_packages(*t);
			break;
		case 2:
			scanf("%s", town_name);
			town* source = find_town(towns, towns_count, town_name);
			int source_index;
			scanf("%d", &source_index);
			scanf("%s", town_name);
			town* target = find_town(towns, towns_count, town_name);
			int target_index;
			scanf("%d", &target_index);
			send_all_acceptable_packages(source, source_index, target, target_index);
			break;
		case 3:
			printf("Town with the most number of packages is %s\n", town_with_most_packages(towns, towns_count).name);
			break;
		}
	}
	return 0;
}
