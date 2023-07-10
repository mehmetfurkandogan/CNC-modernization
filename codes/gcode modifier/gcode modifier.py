

input_file = open("input.txt", "r")
output_file = open("output.txt", "w")
input_list = input_file.readlines()
output_list = []
# T_flag = False
M6_flag = False
Tool_number = 1
prev_tool_number = 0
edited_line = ""
pure_command = ""

for line in input_list:
    non_comment = line.split(";")[0]
    commands = non_comment.split(" ")
    for command in commands:
        pure_command = command.replace("\n", "")
        if pure_command.startswith("T") and (47 < ord(pure_command[1]) < 58): #If The command stars with T and there is a number after it, enters the if statement
            prev_tool_number = Tool_number
            Tool_number = int(pure_command[1:])
        elif pure_command.startswith("M06") or pure_command.startswith("M6"):
            M6_flag = True
        elif pure_command.startswith("M02") or pure_command.startswith("M30"):
            edited_line += "M08\nG4 P150\nM9\nG4 P" + str(round(((7-Tool_number) % 6)*3, 2)) + pure_command
        else:
            edited_line += pure_command + " "

    if M6_flag:
        if 7 > Tool_number > 0:

            output_list.append("M08\n")
            output_list.append("G4 P" + str(round(Tool_number*0.1+0.050, 2)) + "\n")
            output_list.append("M09\n")
            output_list.append("G4 P" + str(round(((Tool_number - prev_tool_number + 6) % 6) * 3, 2)) + "\n")

        else:
            print("There are only 6 tools")
            exit()
        M6_flag = False

    output_list.append(edited_line[:-1] + "\n")
    print(output_list)
    edited_line = ""


output_file.writelines(output_list)
output_file.close()
input_file.close()
