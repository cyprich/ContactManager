build: main.cpp
	@echo "Compiling..."
	@g++ -o main main.cpp Manager.cpp Contact.cpp

run: build 
	@echo "Running..."
	@echo ""
	@./main

clear:
	@rm -f main
	@echo "All clean!"
