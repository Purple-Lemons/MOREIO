**This Project Was Was Designed and Submitted as part of a university course, hence the odd form of the README**

This is MOREIO, an artificial neural network potentialy capable of performing various tasks, although currently is limited to playing 
a bad platformer game over and over, which I also wrote (hastily). The name comes from MAR/IO a neural network which plays Super 
Mario Brothers, which this ANN is inspired by but not based off of.

MOREIO uses genetic algorithms to train itself to learn how to perform it's task, so runs 20 different networks per generation before 
evolving and improving at the game.

The neural network is displayed as an overlay over the game so that you can see which neurons are firing.

References:
http://www.ai-junkie.com/ga/intro/gat1.html : For the genetic algorithms 
http://www.ai-junkie.com/ann/evolved/nnt1.html : For understanding how to apply genetic algorithms to AANs and a few concepts such as storing the threshold with the weights, but my code isn't too similar to this
http://openframeworks.cc/documentation/ : For various syntacitcal things in open frame works such as font loading

Other Information:
This is a Visual Studio 2015 version 14.0.25424.0 project, so the VC++ Project File should just open in visual studio 2015, 
however if you are using a different IDE and just import the source files, make sure to keep the folder structure so that 
the includes work.

Most of the requirements are met in the UI and the actual ANN code. Inheritance things can be found in the GenericNode and other Node classes 
as well as the UIElement, Button, TextBox etc. Pointers are used throughout the program but largely in the UI.

Controls:
There are three buttons in the top left of the screen which allow to load new, pre trained and the most recent network that has run.
