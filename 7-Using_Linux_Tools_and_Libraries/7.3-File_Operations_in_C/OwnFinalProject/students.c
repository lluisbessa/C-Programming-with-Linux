#include "headers.h"

char *subjects[] = {
                        "Mathematics",
                        "English",
                        "Physics",
                        "History",
                        ""
                   };

int checkSubject(char * subject){ // Function for checking if the subject is allowed.
    int found = 0;
    int i;
    for (i=0; i<5; i++){
        if (strncmp(subject, subjects[i], strlen(subject)) == 0){
            found = 1;
            return found;
        }
    }
    return found;
}

int searchStudent(char * firstname, char * lastname, char *subject){
    // Variable initialization
    int i;
    int found = 0;
    char fullname[50] = "";
    // Convert strings with spaces from form arguments to only strings (trim_whitespaces())
    strcat(fullname,trim_whitespaces(firstname)); // Copy firstname and lastname to fullname variable
    strcat(fullname," ");
    strcat(fullname,trim_whitespaces(lastname));
    struct json_object *root = json_object_from_file("db.json"); // Open json
    struct json_object *context; 
    if (checkSubject(trim_whitespaces(subject))==0){ // Check if subject is accepted, if not print accepted subjects, and return from function.
        printw("Subject not accepted, accepted subjects are:");
        for (i=0; i<5; i++){
            printw(" %s", subjects[i]);
        }
        return found; 
    } else if (!root){ // Return if there is no db.json.
        printw("Records not found");
        return found;
    }
    context = json_object_object_get(root, fullname); // Search fullname, if there isn't any student with that name return.
    if (context == NULL){ 
        return found;
    }
    json_object_object_foreach(context, key, val) // If there is a student with that name, search foreach subject and print it. 
        if (strncmp(key,trim_whitespaces(subject),strlen(subject))==0){ 
            found = 1;
            printw("%s: {\"%s\":%s}", fullname,trim_whitespaces(subject),json_object_to_json_string_ext(json_object_object_get(context, trim_whitespaces(subject)), JSON_C_TO_STRING_PRETTY));
        }
    if (!found && strncmp(trim_whitespaces(subject),"",1)!=0){ // If not found, print that information
        printw("These student exists, but it's not doing these subject. "); 
    }
    return found;
}

int searchStudentNoSubject(char * firstname, char * lastname){
    int found = 0;
    char fullname[50] = "";
    strcat(fullname,trim_whitespaces(firstname));
    strcat(fullname," ");
    strcat(fullname,trim_whitespaces(lastname));
    struct json_object *root = json_object_from_file("db.json");
    struct json_object *context;
    if (!root){
        printw("Records not found");
        return found;
    }
        context = json_object_object_get(root, fullname);
    if (context != NULL){
        found = 1;
        printw("%s: %s", fullname,json_object_to_json_string_ext(context, JSON_C_TO_STRING_PRETTY));
        }

    return found;
}


void addStudent(char * firstname, char * lastname){
    struct json_object *root = json_object_from_file("db.json");
    char fullname[50] = "";
    strcat(fullname,trim_whitespaces(firstname));
    strcat(fullname," ");
    strcat(fullname,trim_whitespaces(lastname));
    if (strlen(trim_whitespaces(lastname)) == 0 || strlen(trim_whitespaces(firstname)) == 0){ // If any part of the name is empty return
        printw("Student firstname, lastname or both are empty.");
        return;
    }
    if (!searchStudentNoSubject(firstname, lastname) && root != NULL){ // If there is no such student and root isn't null, append student.
        json_object_object_add(root, fullname, json_object_new_object());
        json_object_to_file("db.json", root);
        printw("\nStudent added succesfully");
    } else if (!root) { // If root is null create a new file with new structure.
        root = json_object_new_object();
        json_object_object_add(root, fullname, json_object_new_object());
        json_object_to_file("db.json", root);
        printw("\nStudent added succesfully");
    } else {
        printw("\nStudent already exists."); // Else student exists.
    }
}

void updateStudent(char * beforefirstname, char * beforelastname, char * newfirstname, char * newlastname, char * subject, char * grade){
    // Initial variable declaration
    struct json_object * root = json_object_from_file("db.json");
    struct json_object * entry, * change;
    int i;
    int foundNoSubject, found;
    char fullname[50] = "";
    char newfullname[50] = "";
    strcat(fullname,trim_whitespaces(beforefirstname));
    strcat(fullname," ");
    strcat(fullname,trim_whitespaces(beforelastname));
    strcat(newfullname,trim_whitespaces(newfirstname));
    strcat(newfullname," ");
    strcat(newfullname,trim_whitespaces(newlastname));
    if (!root) { // If root is null records not found
        printw("Records not found");
        return;
    }
    if (strncmp(trim_whitespaces(subject),"",1)==0 || !checkSubject(subject)){ // If subject is empty or invalid, print accepted subjects.
        printw("Subject not accepted, accepted subjects are:");
            for (i=0; i<5; i++){
            printw(" %s", subjects[i]);
            }
        return;
    }
    if (!(foundNoSubject = searchStudentNoSubject(beforefirstname, beforelastname)) && !(found = searchStudent(beforefirstname, beforelastname, subject))){ // If student doesn't exists print it.
        printw("Student doesn't exist.");
    } else if (found && strncmp(fullname, newfullname,strlen(fullname)) == 0 && strncmp(fullname, newfullname,strlen(newfullname)) == 0){ // If subject is found and beforefullname and newfullname is equal update subject.
        entry = json_object_object_get(root,fullname);
        json_object_object_del(entry, trim_whitespaces(subject));
        json_object_object_add(entry, trim_whitespaces(subject),  json_object_new_string(trim_whitespaces(grade)));
        json_object_to_file("db.json", root);
        printw("\nStudent updated");
    } else if (found){ // Else if is found but names are not equal, create a new key with the newname, update all it's values, remove subject and create a new with the updated grade.
        entry = json_object_object_get(root,fullname);   
        json_object_object_add(root, newfullname, json_object_new_object());
        change = json_object_object_get(root,newfullname);
        json_object_object_foreach(entry, key, val) // Iterate through all objects and add them to the new name.
            json_object_object_add(change, key, val);
        json_object_object_del(change, trim_whitespaces(subject));
        json_object_object_add(change, trim_whitespaces(subject),  json_object_new_string(trim_whitespaces(grade)));
        json_object_object_del(root,fullname);
        json_object_to_file("db.json", root);  
        printw("\nStudent updated and renamed.");
    } else if (foundNoSubject && strncmp(fullname, newfullname,strlen(fullname)) == 0 && strncmp(fullname, newfullname,strlen(newfullname)) == 0) { // Same as before but without old subject, we create a new  subject.
        entry = json_object_object_get(root,fullname);
        json_object_object_add(entry, trim_whitespaces(subject),  json_object_new_string(trim_whitespaces(grade)));
        json_object_to_file("db.json", root);
        printw("\nSubject added to student and student renamed.");
    } else {  // Same as before changing the name, but creating a new subject
        entry = json_object_object_get(root,fullname);
        json_object_object_add(root, newfullname, json_object_new_object());
        change = json_object_object_get(root,newfullname);
        json_object_object_foreach(entry, key, val)
            json_object_object_add(change, key, val);
        json_object_object_add(change, trim_whitespaces(subject),  json_object_new_string(trim_whitespaces(grade)));
        json_object_object_del(root,fullname);
        json_object_to_file("db.json", root);
        printw("\nSubject added to student and student renamed.");  
    }
}

void removeStudent(char * firstname, char * lastname, char * subject){
    char fullname[50] = "";
    struct json_object *root = json_object_from_file("db.json");
    struct json_object *entry;
    strcat(fullname,trim_whitespaces(firstname));
    strcat(fullname," ");
    strcat(fullname,trim_whitespaces(lastname));
    if (!root){ // If there is no root, print this.
        printw("No records found, go add new records.");
        return;
    }
    if (searchStudent(firstname, lastname, subject)){ // If there is a student with that subject, delete only the subject.
        entry = json_object_object_get(root,fullname);
        json_object_object_del(entry,trim_whitespaces(subject));
        json_object_to_file("db.json", root);
        printw("\nDeleted.");
    } else if (strlen(trim_whitespaces(subject))>0){
        printw("Student doesn't have this subject.");
    } else if (searchStudentNoSubject(firstname, lastname)){ // Else if, there is a student with that name but withouth that subject delete the student.
        json_object_object_del(root,fullname);
        json_object_to_file("db.json", root);
        printw("\nDeleted.");
    } else { // Else there are no records from these student.
        printw("\n\nNo record to replace found.");
    } 
}
