#================================================#
# This code is generated by Bing Chat (AI)
# Questions by Fayed
#================================================#

# Create a list to store the telephone data
telephone_data = []

# Add new data to the list
add_data("John Smith", "123 Main St.", "555-1234")
add_data("Jane Doe", "456 Elm St.", "555-5678")

# Read data from the list
read_data("John Smith")

# Update data in the list
update_data("Jane Doe", "789 Oak St.", "555-9012")

# Read data from the list
read_data("Jane Doe")

# Create a function to add new data to the list
func add_data(name, address, phone)
    telephone_data + [name, address, phone] // Add new data to the list
    print("Data added successfully!" + nl)
end

# Create a function to read data from the list
func read_data(name)
    found = false
    for i = 1 to len(telephone_data)
        if telephone_data[i][1] = name
            print("Name: " + telephone_data[i][1] + nl)
            print("Address: " + telephone_data[i][2] + nl)
            print("Phone: " + telephone_data[i][3] + nl)
            found = true
            break
        end
    end
    if not found
        print("Data not found!" + nl)
    end
end

# Create a function to update data in the list
func update_data(name, address, phone)
    found = false
    for i = 1 to len(telephone_data)
        if telephone_data[i][1] = name
            telephone_data[i] = [name, address, phone]
            print("Data updated successfully!" + nl)
            found = true
            break
        end
    end
    if not found
        print("Data not found!" + nl)
    end
end

# Create a function to delete data from the list
func delete_data(name)
    found = false
    for i = 1 to len(telephone_data)
        if telephone_data[i][1] = name
            telephone_data = telephone_data - [telephone_data[i]]
            print("Data deleted successfully!" + nl)
            found = true
            break
        end
    end
    if not found
        print("Data not found!" + nl)
    end
end