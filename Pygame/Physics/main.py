import pygame, sys, pymunk # importing modules 

def create_apple(space,pos):
	body = pymunk.Body(1,100,body_type = pymunk.Body.DYNAMIC)
	body.position = pos
	shape = pymunk.Circle(body,80)
	space.add(body,shape)
	return shape

def draw_apples(apples):
	for apple in apples: 
		pos_x = int(apple.body.position.x)
		pos_y = int(apple.body.position.y)
		apple_rect = apple_surface.get_rect(center = (pos_x,pos_y))
		screen.blit(apple_surface,apple_rect)

def static_ball(space):
	body = pymunk.Body(body_type = pymunk.Body.STATIC)
	body.position = (500,500)
	shape = pymunk.Circle(body,50)
	space.add(body,shape)
	return shape

def draw_static_ball(balls):
	for ball in balls:
		pos_x = int(ball.body.position.x)
		pos_y = int(ball.body.position.y)
		pygame.draw.circle(screen,(0,0,0),(pos_x,pos_y),50)

pygame.init() # initating pygame
screen = pygame.display.set_mode((800,800)) # creating the display surface
clock = pygame.time.Clock() # creating the game clock
space = pymunk.Space()
space.gravity = (0,500)
apple_surface = pygame.image.load('apple.png')
apples = []

balls = []
balls.append(static_ball(space))

while True: # Game loop
	for event in pygame.event.get(): # checking for user input
		if event.type == pygame.QUIT: #input to close the game
			pygame.quit()
			sys.exit()
		if event.type == pygame.MOUSEBUTTONDOWN:
			apples.append(create_apple(space,event.pos))

	screen.fill((217,217,217)) # background color
	draw_apples(apples)
	draw_static_ball(balls)
	space.step(1/50)
	pygame.display.update() # rendering the frame
	clock.tick(120) # limting the frames per second to 120