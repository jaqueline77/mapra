CXXFLAGS = -O0 -g

prog: meina2b.cpp unit.o student.o sort.h
	$(CXX) $(CXXFLAGS) -o $@ $^

student.o: student.cpp student.h
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f student.o prog

.PHONY: clean
