const Twilio = require("twilio");

const client = new Twilio(
    "AC28afb5a4c6b960d759fc4c70d39e0b3f",
    "86783880289cb4251350d42f9ed55ce8"
    );

client.messages
    .list()
    .then(messages => 
        console.log(`The most recent message is ${messages[0].body}`)
    ).catch(err => console.error(err) );

console.log('Gathering your message log');