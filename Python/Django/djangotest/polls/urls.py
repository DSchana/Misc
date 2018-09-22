from django.urls import path
from . import views

app_name = "polls"
urlpatterns = [
	path("", views.index, name="index"),
	path("<int:q_id>/", views.details, name="details"),
	path("<int:q_id>/results", views.results, name="results"),
	path("<int:q_id>/vote", views.vote, name="vote")
]
