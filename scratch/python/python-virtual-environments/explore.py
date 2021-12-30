from twilio.rest import Client 

client = Client(
    "AC28afb5a4c6b960d759fc4c70d39e0b3f", 
    "86783880289cb4251350d42f9ed55ce8"
    )

#for msg in client.messages.list():
#    print(msg.body)

msg = client.messages.create(
    
)