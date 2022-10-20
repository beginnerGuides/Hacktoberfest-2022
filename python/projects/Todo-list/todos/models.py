from distutils.command.upload import upload
from email.policy import default
from trace import Trace
from django.db import models
from django.contrib.auth.models import User
from django.db.models import Model

# Create your models here.


class Task(models.Model):
    
    user = models.ForeignKey(
        User, on_delete=models.CASCADE, null=True, blank=True)
    title = models.CharField(max_length=200)
    description = models.TextField(null=True, blank=True)
    deadline = models.CharField(max_length=30)
    complete = models.BooleanField()


    def __str__(self):
        return self.title

    class Meta:
        ordering = ['complete']
    


class Profile(models.Model):
    user = models.OneToOneField(User, on_delete=models.CASCADE)
    image = models.ImageField(default='default.jpg', upload_to='profile_pics')
    email = models.EmailField(max_length = 254, default='default.jpg') 

    def __str__(self):
        return f'{self.user.username} Profile'