#Celeste Pava

import os

#Function to clear screen
def clear_screen():
    if os.name == 'nt':
        os.system('cls')  # For Windows
    else:
        os.environ['TERM'] = 'xterm'  # Set TERM to 'xterm' for other platforms like macOS and Linux
        os.system('clear')

#Welcome msg
print(f"Welcome to the spaceship text adventure game!\n", '-' * 27)
print("You are a golden retriever dog who’s been taken captive aboard an alien spacecraft.")
print(
    "Your mission is to collect all the items to defeat the alien. \nYou will need, a key, a gate opener, "
    "an iPod (for an intergalactic alien fighting soundtrack) \na radiation shield, a laser beam and a slice of key-lime pie to fuel up for battle! "
    "\nYou must collect all items before you encounter the alien. "
    "\nYou will not have a map, so you must remember what rooms you have been to.")
input("\nPress enter/return to continue...")
clear_screen()

def main():
    #Dictionary containing rooms and their locations to each other
    rooms = {
        'Command Center': {'south': 'Cafeteria', 'north': 'Service Closet', 'east': 'Skybridge', 'west': 'Armory'},
        'Cafeteria': {'north': 'Command Center', 'east': "Captains' Quarters", 'Item': 'Key-lime Pie'},
        "Captains' Quarters": {'west': 'Cafeteria', 'Item': 'Radiation Shield'},
        'Service Closet': {'south': 'Command Center', 'east': 'Smugglers Hold', 'Item': 'iPod'},
        'Smugglers Hold': {'west': 'Service Closet', 'Item': 'Gate Opener'},
        'Armory': {'east': 'Command Center', 'Item': 'Laser Beam'},
        'Skybridge': {'west': 'Command Center', 'north': 'Throne Room', 'Item': 'Key'},
        'Throne Room': {'south': 'Skybridge', 'Item': 'Alien'}
    }

    #possible moves player can make
    moves = ["go north", "go east", "go west", "go south"]
    current_room = 'Command Center'
    inventory = []
    #vowels to determine spelling in messages
    vowels = ['a', 'e', 'i', 'o', 'u']

    #Print instructions to player
    def instructions():
        print("-" * 27)
        print("Moves you can make: go North, go East, go West, go South or Pick up item")
        if len(inventory) == 0:
            print("Your inventory is currently empty.")
        print(f'Inventory: {inventory}')
        print(f"You are in the: {current_room}")

    #While loop to run until player collects all items
    while len(inventory) < 7:
        if current_room != "Throne Room":
            print()
            instructions()
            if 'Item' in rooms[current_room]:
                if rooms[current_room]['Item'] not in inventory:
                    item = rooms[current_room]['Item']
                    if item[0] in vowels:
                        an = 'an'
                    else:
                        an = 'a'
                    print(f"You see {an} {rooms[current_room]['Item']} nearby")


        # Get players first move
        move = input("Type in your move: \n> ").lower()
        clear_screen()
        if move not in moves:
            if move != 'pick up item':
                print("\nInvalid move, please try again.")


        # Check if move is possible
        elif move in moves:
            #If the move is a valid direction but not possible from current room
            if move.split(" ")[-1] not in rooms[current_room]:
                print("\nYou can't go there")
            #If move is possible move player to that room
            elif move.split(" ")[-1] in rooms[current_room]:
                current_room = rooms[current_room][move.split(" ")[-1]]
                clear_screen()

        if move == 'pick up item':
            if 'Item' not in rooms[current_room]:
                print(f"There is no item to pick up")
            elif 'Item' in rooms[current_room]:
                if rooms[current_room]['Item'] not in inventory:
                    inventory.append(rooms[current_room]['Item'])
                    clear_screen()
                elif rooms[current_room]['Item'] in inventory:
                    print(f"You already have the {rooms[current_room]['Item']}")
        #If player reaches throne room before collecting all items
        elif current_room == 'Throne Room':
            if len(inventory) < 6:
                print("\nOh no, you don't have all the items")
                print("DUN\n DUN\n DUN\n DUN")
                print("The alien approaches......")
                print('NOM NOM NOM NOM')
                print("You have lost the game......")
                exit()
            elif len(inventory) == 6:
                break

    last_item = inventory[-1]
    #Choose what word to use depending on spelling
    if last_item[0] in vowels:
        word = 'and an'
    else:
        word = 'and a'

    print("You have reached the Throne Room")
    print("The alien approaches......")
    print(f'Good thing you have the {inventory[0:-1]} {word} {inventory[-1]} in your inventory')
    print('ANDDDD')
    print("You use your shield, and blast him with the laser beam!!!!")
    print("Congratulations, you have won the game!!")

if __name__ == '__main__':
    main()

