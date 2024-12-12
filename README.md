The Poll Conductor project is an interactive C++ application that allows users to conduct polls by loading questions and their corresponding options from an input file. It provides functionality for recording user responses and generating results, making it a simple and effective tool for gathering feedback or conducting surveys. The project demonstrates the use of object-oriented programming concepts like classes and inheritance, as well as file handling for input and output operations.

Key Features:
1.Dynamic Question Loading:
  Questions and options are loaded dynamically from a file (poll_questions.txt).
  Input format:
  Question statement ?::option1,option2,...

2.User Interaction:
  Users can respond to polls by selecting options for each question.
  Supports multiple user responses in a single session.
  Option to exit the poll at any time.
  
3.Result Compilation:
  Captures and stores responses for each option in real-time.
  Generates a detailed results summary with vote counts and percentages.
  Outputs results to a file (user_responses.txt) for analysis.

4.Robust Design:
  Handles invalid input files with error messages.
  Allows for a maximum of 10 questions and 10 options per question.
  Ensures responses are saved before exiting.
