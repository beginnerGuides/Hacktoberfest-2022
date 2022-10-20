from django.contrib import admin

from .models import Task
from .models import Profile


# Register your models here.

admin.site.register(Task)
admin.site.register(Profile)