from django.db import models

# Create your models here.
class Student(models.Model):
    name = models.CharField(max_length=200, null=True)
    roll_no = models.IntegerField(null=True)
    semester = models.IntegerField(null=True)
    division = models.CharField(max_length=20, null=True)
    department = models.CharField(max_length=200, null=True)

    def __str__(self):
        return self.name
