const functions = require('firebase-functions');
const admin = require('firebase-admin');
const crypto = require('crypto');

admin.initializeApp();

exports.requestHandler = functions.https.onRequest(async (request, response) => {
    const uriData = new URL(request.url, `http://${request.headers.host}`);
    const pathname = uriData.pathname; // /firmware.bin

    if (pathname === '/firmware.bin') {
        const ver = request.headers['x-esp8266-version'];
        console.log('Client request update, version ', ver);

        if (ver === '1.0') {
            console.log('Send firmware 2.0 to client');
            const bucket = admin.storage().bucket();
            const file = bucket.file('firmware.bin');

            try {
                const [content] = await file.download();
                const md5Hash = crypto.createHash('md5').update(content).digest("hex");

                response.writeHead(200, {
                    'Content-Type': 'binary/octet-stream',
                    'Content-Length': content.length,
                    'x-MD5': md5Hash
                });
                response.end(content);
            } catch (error) {
                console.error('Error reading firmware file:', error);
                response.status(500).send('Error loading firmware');
            }
        } else {
            response.statusCode = 304;
            response.end();
        }
    } else {
        response.status(404).send('Not Found');
    }
});
