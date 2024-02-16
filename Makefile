CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
SRC = my_bsq* c/my_string.c c/map.c
TARGET = my_bsq

$(TARGET): $(SRC)
  $(CC) $(CFLAGS) -o $(TARGET) $(SRC)

.PHONY: fclean

fclean:
  rm -r $(TARGET)

clean:
  rm -rf $(TARGET)
