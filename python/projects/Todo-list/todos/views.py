# pylint: disable=unused-import
from django.forms import fields_for_model
from django.shortcuts import render
from django.views.generic.list import ListView
from django.views.generic.detail import DetailView
from django.views.generic.edit import CreateView, UpdateView, DeleteView, FormView
from django.urls import reverse_lazy

from django.contrib.auth.models import AnonymousUser


from django.contrib.auth.views import LoginView


from django.contrib.auth.decorators import login_required




# from django.contrib.auth.mixins import LoginRequiredMixin

from django.contrib.auth.forms import UserCreationForm
from django.contrib.auth import login



from .models import Task



# Create your views here.
class CustomLoginView( LoginView):
    template_name = 'todos/login.html'
    fields = '__all__'
    redirect_authenticated_user = True

    def get_success_url(self):
        return reverse_lazy('tasks')


class RegisterPage(FormView):
    template_name = 'todos/register.html'
    form_class = UserCreationForm
    redirect_authenticated_user = True
    success_url = reverse_lazy('tasks')



    def form_valid(self, form):
        user = form.save()
        if user is not None:
            login(self.request, user)
        return super(RegisterPage, self).form_valid(form)


    # def get(self, *args, **kwargs):
    #     if self.request.user.is_authenticated:
    #         return redirect('tasks')
    #     return super(RegisterPage, self).get(*args, **kwargs)






class TaskList( ListView):
    model = Task
    context_object_name = 'tasks'


    def get_context_data(self, **kwargs):
        context = super().get_context_data(**kwargs)
        context['tasks'] = context['tasks'].filter(user=self.request.user)
       
        return context


class TaskDetail(DetailView):
    model = Task
    context_object_name = 'task'


class TaskCreate(CreateView):
    model = Task
    fields = ['title', 'description', 'deadline', 'complete']
    success_url = reverse_lazy('tasks')


    def form_valid(self, form):
        form.instance.user = self.request.user
        return super(TaskCreate, self).form_valid(form)

    # def get(self, *args, **kwargs):
    #     if self.request.user.is_authenticated:
    #         return redirect('tasks')
        
    #     return super(RegisterPage, self).get(*args, **kwargs)


class TaskUpdate(UpdateView):
    model = Task
    fields = ['title', 'description', 'deadline', 'complete']
    success_url = reverse_lazy('tasks')


class DeleteView(DeleteView):
    model = Task
    context_object_name = 'task'
    success_url = reverse_lazy('tasks')


@login_required
def profile(request):
    return render(request, 'todos/profile.html')
    