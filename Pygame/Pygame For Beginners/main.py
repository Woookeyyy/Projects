import pygame
import os 

#Variables

#Defining the width and the height of the window
WIDTH, HEIGHT = 900, 500

#Creating a window display
WIN = pygame.display.set_mode((WIDTH,HEIGHT))

#setting a caption
pygame.display.set_caption("First Game!")

#Color
WHITE = (255, 255, 255)
BLACK = (0, 0, 0)

# Slipt the window into two
BORDER = pygame.Rect(WIDTH/2 - 5,0,10,HEIGHT)

#Setting FPS
FPS = 60

#Velocity 
VEL = 5

# Bullet speed
BULLET_VEL = 7

#The max number of bullets
MAX_BULLETS =
#Define images width and height
SPACESHIP_WIDTH, SPACESHIP_HEIGHT = 55, 40

#Adding and resizing and rotating image 1
YELLOW_SPACESHIP_IMAGE = pygame.image.load(os.path.join('Pygame','Assets', 'spaceship_yellow.png'))
YELLOW_SPACESHIP = pygame.transform.rotate(pygame.transform.scale(YELLOW_SPACESHIP_IMAGE,(SPACESHIP_WIDTH,SPACESHIP_HEIGHT)), 90)

#Adding and resizing and rotating image 2
RED_SPACESHIP_IMAGE = pygame.image.load(os.path.join('Pygame','Assets', 'spaceship_red.png'))
RED_SPACESHIP = pygame.transform.rotate(pygame.transform.scale(RED_SPACESHIP_IMAGE,(SPACESHIP_WIDTH,SPACESHIP_HEIGHT)), 270)

#Draws to the window
def draw_window(red, yellow):
     WIN.fill(WHITE)
     pygame.draw.rect(WIN, BLACK, BORDER)
     WIN.blit(YELLOW_SPACESHIP, (yellow.x,yellow.y))
     WIN.blit(RED_SPACESHIP, (red.x, red.y))
     pygame.display.update()

 # Get a list of all the keys that are currently being pressed down and check if the ones we are looking for is being pressed down if there are respond to that press. 
 # if the keys is still pressed down it will still registered
def handle_yellow_movement(keys_pressed, yellow): 
     if keys_pressed[pygame.K_a] and yellow.x - VEL > 0: #LEFT
        yellow.x -= VEL
     if keys_pressed[pygame.K_d] and yellow.x + VEL + yellow.width < BORDER.x : #RIGHT
        yellow.x += VEL
     if keys_pressed[pygame.K_w] and yellow.y - VEL > 0: #UP
        yellow.y -= VEL
     if keys_pressed[pygame.K_s]and yellow.y + VEL + yellow.height < HEIGHT - 15: #DOWN
        yellow.y += VEL

def handle_red_movement(keys_pressed, red): 
    
     if keys_pressed[pygame.K_LEFT] and red.x - VEL > BORDER.x + BORDER.width: #LEFT
        red.x -= VEL
     if keys_pressed[pygame.K_RIGHT] and red.x + VEL + red.width < WIDTH: #RIGHT
        red.x += VEL
     if keys_pressed[pygame.K_UP] and red.y - VEL > 0: #UP
        red.y -= VEL
     if keys_pressed[pygame.K_DOWN] and red.y + VEL + red.height < HEIGHT - 15: #DOWN
        red.y += VEL

# Game loop
def main():
    red = pygame.Rect(700,300, SPACESHIP_WIDTH, SPACESHIP_HEIGHT)
    yellow = pygame.Rect(100,300, SPACESHIP_WIDTH, SPACESHIP_HEIGHT)

    red_bullets = []
    yellow_bullets = []

    clock = pygame.time.Clock()
    run = True
    while run:
        clock.tick(FPS)
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                run = False


            if event.type == pygame.KEYDOWN:
               if event.key == pygame.K_LCTRL:
                  bullet = pygame.rect(yellow.x + yellow.width, yellow.y + yellow.height/2 - 2, 10, 5)
                  yellow_bullets.append(bullet)


               if event.key == pygame.K_RCTRL:
                  bullet = pygame.rect(red.x, red.y + red.height/2 - 2, 10, 5)
                  yellow.append(bullet)

               
        keys_pressed = pygame.key.get_pressed()
        handle_yellow_movement(keys_pressed, yellow)

        handle_red_movement(keys_pressed, red)

        #draws the image
        draw_window(red, yellow)
       

    pygame.quit()

if __name__ == "__main__":
    main()