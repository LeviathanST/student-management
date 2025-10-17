typedef struct {
  char subject[15];
  int value;
} Score;

/// Get all scores of a student from the file.
/// @return a score array of a student
Score *score_getAll(const char *student_id);

/// Write a key pair subject - value of a student to the file.
void score_write(const char *student_id, const char *subject, int value);

/// Calculate GPA of a student.
void score_calcGPA(const char *student_id);
