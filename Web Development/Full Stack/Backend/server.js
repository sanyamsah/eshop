import express from 'express'; // module js syntax // add "type":"module", in package.json
const app = express();

app.get('/', (req, res) => {
    res.send('Server is ready');
})

app.get('/api/jokes', (req, res) => {
    const jokes = [
        {
            "id": 1,
            "title": "Joke 1",
            "content": "This is joke number 1"
        },
        {
            "id": 2,
            "title": "Joke 2",
            "content": "This is joke number 2"
        },
        {
            "id": 3,
            "title": "Joke 3",
            "content": "This is joke number 3"
        },
        {
            "id": 4,
            "title": "Joke 4",
            "content": "This is joke number 4"
        },
        {
            "id": 5,
            "title": "Joke 5",
            "content": "This is joke number 5"
        }
    ];
    res.send(jokes);
})

const port = process.env.PORT || 3000;

app.listen(port, () => {
    console.log(`Serve at http://localhost:${port}`);
});