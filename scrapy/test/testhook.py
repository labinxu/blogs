from discord_webhook import DiscordWebhook, DiscordEmbed

webhook = DiscordWebhook(url='https://discordapp.com/api/webhooks/769212715108401172/YlRV9iRGwpKlxO732SCcgWGbQzG3KREEiflOG_SIjc0otq07scbcpU9wAr__stqS3oQq')

# create embed object for webhook
embed = DiscordEmbed(title='abc mart ets', description='order finished', color=242424)

# add embed object to webhook
webhook.add_embed(embed)

response = webhook.execute()
#137.220.240.253:42063:mulgmqzc:skmyqbml