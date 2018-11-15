from django.shortcuts import render, get_object_or_404
from django.http import HttpResponse, Http404
from .models import Question

def index(req):
	latest_question_list = Question.objects.order_by("-date")[:5]

	return HttpResponse(render(req, "polls/index.html", { "latest_question_list": latest_question_list }))

def details(req, q_id):
	q = get_object_or_404(Question, pk=q_id)

	return HttpResponse(render(req, "polls/details.html", { "question": q }))

def results(req, q_id):
	return HttpResponse("You're at results of %s" % q_id)

def vote(req, q_id):
	return HttpResponse("You're at vote of %s" % q_id)
