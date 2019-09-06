#include <stdio.h>

#ifndef STRING_MAX
#define STRING_MAX 150
#endif

#ifndef INT_MAX
#define INT_MAX 150
#endif

#ifndef DOUBLE_MAX
#define DOUBLE_MAX 150
#endif

#ifndef TABLE_MAX
#define TABLE_MAX 150
#endif

#ifndef DATABASE_MAX
#define DATABASE_MAX 150
#endif

struct table {
  char string_column[STRING_MAX][STRING_MAX];
  char table_name[TABLE_MAX];
  int int_column[INT_MAX];
  double double_column[DOUBLE_MAX];
  int id;
};

struct database {
 // struct table user_tables[TABLE_MAX];
 char database_name[STRING_MAX];
 int id[INT_MAX];
};

struct query {
 struct database user_databases[DATABASE_MAX];
};

// ==== PROTOTYPE FUNCTIONS ==== //
void create_database();
void show_databases();
int use_databases();
void create_table(struct database *db);

int str_cmp(char str_1[], char str_2[]);
int find_user();

// ==== PRINT INSTRUCTION FUNCTIONS ==== //
void print_home_commands();
void enter_home_ui();


// ==== MAX DATABASE VALUES ==== //
int int_max = INT_MAX;
int table_max = TABLE_MAX;
int string_max = STRING_MAX;
int double_max = DOUBLE_MAX;
int database_max = DATABASE_MAX;
int database_tracker = 0;
int table_tracker = 0;

// ==== USER COMMANDS ==== //
char quit[] = "00";

// ==== MY QUERY ==== //
struct database my_database[DATABASE_MAX];

// ==== BEGIN MAIN FUNCTION ==== //
int main(int argc, char const *argv[]) {

  // ==== USER COMMANDS ==== //
  char enter_cli[] = "99";

  char user_input[] = "zz";

  printf("\n\n** -- Welcome To The Stuctured Database CLI -- **\n\n");

  while (str_cmp(user_input, quit) != 0) {

    printf("\n\n** -- QUIT -- 00 -- **\n");
    printf("** -- ENTER CLI -- 99 -- **\n\n");
    printf(" --> ");
    scanf("%s", user_input);

    if (str_cmp(user_input, quit) == 0) {
      printf("\nBye!\n");
    } else if (str_cmp(user_input, enter_cli) == 0) {
      enter_home_ui();
    }
  }

  return 0;
}
// ==== END MAIN FUNCTION ==== //

void create_database() {

  // ==== USER COMMANDS ==== //
  char drop_database[] = "11";

  printf("Please Enter Your Database Name\n");
  printf(" --> ");

  scanf("%s", my_database[database_tracker].database_name);

  my_database[database_tracker].id[database_tracker] = database_tracker;

  printf("The %s database has now been created with id - %d\n",
  my_database[database_tracker].database_name,
  my_database[database_tracker].id[database_tracker]);

  database_tracker++;

}

// void create_table(struct database *db) {
//   printf("Please Enter Your Table Name\n");
//   printf(" --> ");
//
//   scanf("%s", my_database[database_tracker].user_tables[table_tracker].table_name);
//
//   printf("The %s database has now been created\n",
//   my_database[database_tracker].user_tables[table_tracker].table_name);
//
//   table_tracker++;
// }

void show_databases() {

  printf("\n\n------------------------\n");

  for (int i = 0; i < database_tracker; i++) {
    printf("%d | %s", my_database[i].id[i], my_database[i].database_name);
    printf("             ");
    printf("\n");
  }

  printf("------------------------\n");

}

int use_databases() {

  // ==== USER COMMANDS ==== //
  char crt_table[] = "11";
  char show_table[] = "22";
  char drop_table[] = "33";

  char user_input[] = "zz";
  int i = find_user();

  if (i == -1) {
    return 0;
  }

  while (str_cmp(user_input, quit) != 0) {

    printf("\n\n--{ %s }--\n\n", my_database[i].database_name);

    printf("\n\n** -- Quit -- 00 -- **\n");
    printf("** -- Create Table -- 11 -- **\n");
    printf("** -- Show Tables -- 22 -- **\n\n");

    printf(" --> ");
    scanf("%s", user_input);

    if (str_cmp(user_input, quit) == 0) {
      return 0;
    } else if (str_cmp(user_input, crt_table) == 0) {
      // create_table();
    } else if (str_cmp(user_input, show_table) == 0) {
      // show_tables();
    } else {
      printf("** -- Sorry I Don't Recognize That Command -- **\n");
    }

  }

  return 0;
}

void enter_home_ui() {

  // ==== USER COMMANDS ==== //
  char crt_database[] = "11";
  char show_database[] = "22";
  char use_database[] = "33";

  char user_input[] = "zz";

  while (str_cmp(user_input, quit) != 0) {

    print_home_commands();
    printf(" --> ");
    scanf("%s", user_input);

    if (str_cmp(user_input, crt_database) == 0) {
      create_database();
    } else if (str_cmp(user_input, show_database) == 0) {
      show_databases();
    } else if (str_cmp(user_input, use_database) == 0) {
      use_databases();
    } else {
      continue;
    }

  }

}

void print_home_commands() {

  printf("\n\n -- { Home } -- \n");

  printf("\n\n** -- Quit -- 00 -- **\n");
  printf("** -- Create A Database -- 11 -- **\n");
  printf("** -- Show Databases -- 22 -- **\n");
  printf("** -- Use Database -- 33 -- **\n\n");

}

int find_user() {

  int user_id = -1;

  printf("** -- Please Enter Database Id -- **\n");
  printf(" --> ");
  scanf("%d", &user_id);

  for (int i = 0; i <= database_tracker; i++) {
    if (user_id == my_database[user_id].id[user_id]) {
      printf("Now Using %s\n", my_database[user_id].database_name);
      return user_id;
    } else {
      printf("** -- Sorry That Database Doesnt Exist -- **\n");
      return -1;
    }
  }

}

int str_cmp(char str_1[], char str_2[]) {

  int i = 0;
  int j = 0;
  int res_1 = 0;
  int res_2 = 0;

  int res = 0;

  while (str_1[i] != '\0') {
    res_1 += str_1[i];
    i++;
  }

  while (str_2[j] != '\0') {
    res_2 += str_2[j];
    j++;
  }

  if (res_1 == res_2) {
    res = 0;
  } else {
    res = 1;
  }

  return res;
}
