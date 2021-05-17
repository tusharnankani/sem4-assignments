from django.shortcuts import render

# Create your views here.

from .models import *

def home(request):
    students = Student.objects.all()
    context = {'students': students}
    return render(request, 'myapp/index.html', context)